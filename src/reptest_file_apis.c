#define LOG_TITLE "REPETITION_TESTER"
#define COMMON_IMPLEMENTATION
#include "common.h"

#include "benchmark/benchmark_inc.h"
#include "benchmark/benchmark_inc.c"

#include <fcntl.h>
#include <unistd.h>

typedef struct Operation_Parameters Operation_Parameters;
struct Operation_Parameters
{
  String buffer;
  const char *file_name;
};

static
void read_with_fread(Repetition_Tester *tester, Operation_Parameters *params)
{
  while (repetition_tester_is_testing(tester))
  {
    FILE *file = fopen(params->file_name, "rb");
    if (file)
    {
      repetition_tester_begin_time(tester);
      usize result = fread(params->buffer.data, params->buffer.count, 1, file);
      repetition_tester_close_time(tester);

      if (result == 1)
      {
        repetition_tester_count_bytes(tester, params->buffer.count);
      }
      else
      {
        repetition_tester_error(tester, "Unable to read file");
      }

      fclose(file);
    }
    else
    {
      repetition_tester_error(tester, "Unable to open file");
    }
  }
}

static
void read_with_read(Repetition_Tester *tester, Operation_Parameters *params)
{
  while (repetition_tester_is_testing(tester))
  {
    int fd = open(params->file_name, O_RDONLY);

    if (fd != -1)
    {
      repetition_tester_begin_time(tester);
      usize result = read(fd, params->buffer.data, params->buffer.count);
      repetition_tester_close_time(tester);

      if (result == params->buffer.count)
      {
        repetition_tester_count_bytes(tester, params->buffer.count);
      }
      else
      {
        repetition_tester_error(tester, "Unable to read file");
      }

      close(fd);
    }
    else
    {
      repetition_tester_error(tester, "Unable to open file");
    }
  }
}

Operation_Entry test_entries[] =
{
  {String("fread"), read_with_fread},
  {String("read"),  read_with_read},
};

int main(int arg_count, char **args)
{
  if (arg_count != 3)
  {
    printf("Usage: %s [test_file] [seconds_to_try_for_min]\n", args[0]);
    return 1;
  }

  // TODO: This initialization code should be pulled into a prototype implemented by user
  // of library
  usize size = file_size(args[1]);
  String buffer =
  {
    .data  = os_allocate(size, OS_ALLOCATION_COMMIT|OS_ALLOCATION_PREFAULT),
    .count = size,
  };

  // Touch the memory once so no page faults in bench
  // for (usize i = 0; i < buffer.count; i++)
  // {
  //   volatile u8 write = 0;
  //   buffer.data[i] = write;
  // }

  Operation_Parameters params =
  {
    .buffer    = buffer,
    .file_name = args[1],
  };

  u64 cpu_timer_frequency = estimate_cpu_timer_freq();

  u32 seconds_to_try_for_min = atoi(args[2]);

  while (true)
  {
    Repetition_Tester testers[STATIC_ARRAY_COUNT(test_entries)] = {0};

    for (usize i = 0; i < STATIC_ARRAY_COUNT(test_entries); i++)
    {
      Repetition_Tester *tester = &testers[i];
      Operation_Entry *entry = &test_entries[i];

      printf("\n--- %.*s ---\n", String_Format(entry->name));
      repetition_tester_new_wave(tester, size, cpu_timer_frequency, seconds_to_try_for_min);
      entry->function(tester, &params);
    }
  }

  free(buffer.data);
}
