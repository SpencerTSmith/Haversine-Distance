#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
extern "C"
{
#endif

/*
 *
 * Standard stb style thing, yadda yadd
 * put:
 *
 *     #define COMMON_IMPLEMENTATION
 *     #include "common.h"
 *
 * in exactly one file
 *
 * Also to title your log messages use:
 *
 *    #define LOG_TITLE "TITLE"
 *
 * before defining the implementation
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <sys/stat.h>

/////////////////
// QOL/UTILITY
////////////////
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t  i8;

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef int64_t b64;
typedef int32_t b32;
typedef int16_t b16;
typedef int8_t  b8;

#define true  1
#define false 0

typedef double f64;
typedef float  f32;

typedef size_t    usize;
typedef ptrdiff_t isize;

#define CONCAT(a, b) a##b
#define MACRO_CONCAT(a, b) CONCAT(a, b)

#define CLAMP(value, min, max) (((value) < (min)) ? (min) : ((value) > (max)) ? (max) : (value))
#define MAX(first, second) ((first) > (second) ? (first) : (second))
#define MIN(first, second) ((first) > (second) ? (second) : (first))

// Powers of 2 only
#define ALIGN_ROUND_UP(x, b) (((x) + (b) - 1) & (~((b) - 1)))

#define PI 3.14159265358979323846
#define RADIANS(degrees) ((degrees) * (PI / 180))

#define STATIC_ARRAY_COUNT(arr) (sizeof(arr) / sizeof(arr[0]))

#define ZERO_STRUCT(ptr) (memset((ptr), 0, sizeof(*(ptr))))
#define ZERO_SIZE(ptr, size) (memset((ptr), 0, (size)))

#define VOID_PROC ((void)0)

#define KB(n) (1024 * (n))
#define MB(n) (1024 * KB(n))
#define GB(n) (1024L * MB(n)) // L immediate to promote the expression if over 4GB

#define THOUSAND(n) (1000 * (n))
#define MILLION(n) (1000 * THOUSAND(n))
#define BILLION(n) (1000 * MILLION(n))

#define NSEC_PER_SEC BILLION(1)
#define MSEC_PER_SEC THOUSAND(1)

#define DEFER_SCOPE(begin, end) \
  for (isize __once__ = (begin, 0); !__once__; __once__++, (end))

#define ENUM_MEMBER(name) name,
#define ENUM_STRING(name) # name,

// This macro makes it very simple to do enum -> string tables
// Keep in mind that this string table is defined static const so it will
// create a copy in every file that includes a file that uses this macro
// You may prefer to do it in the traditional using the above ENUM_* macros
//
// NOTE(ss): Idea from https://philliptrudeau.com/blog/x-macro
#define ENUM_TABLE(Enum_Name)                  \
  typedef enum Enum_Name                       \
  { Enum_Name(ENUM_MEMBER) } Enum_Name;        \
  static const char *Enum_Name ## _strings[] = \
  { Enum_Name(ENUM_STRING) };

// Only useful if you know exactly how big the file is ahead of time, otherwise probably put on an arena if don't know...
// or use file_size()
usize read_file_to_memory(const char *name, u8 *buffer, usize buffer_size);

usize file_size(const char *name);

// No Null terminated strings!
typedef struct String String;
struct String
{
  u8    *data;
  isize count;
};

#define String(s) (String){(u8 *)s, STATIC_ARRAY_COUNT(s) - 1}

#define String_Format(s) (int)s.count, s.data

b8 strings_equal(String a, String b);

/////////////////
// LOGGING
////////////////
#define LOG_ENUM(X) \
  X(LOG_FATAL)      \
  X(LOG_ERROR)      \
  X(LOG_DEBUG)      \
  X(LOG_INFO)
typedef enum Log_Level
{
  LOG_ENUM(ENUM_MEMBER)
} Log_Level;

// Intended for internal use... probably want to use the macros
void log_message(Log_Level level, const char *file, usize line, const char *message, ...);

#define LOG_FATAL(message, exit_code, ...)                              \
  do                                                                    \
  {                                                                     \
    log_message(LOG_FATAL, __FILE__, __LINE__, message, ##__VA_ARGS__); \
    exit(exit_code);                                                    \
  }                                                                     \
  while (0)
#define LOG_ERROR(message, ...) log_message(LOG_ERROR, __FILE__, __LINE__, message, ##__VA_ARGS__)

#ifdef DEBUG
  #define LOG_DEBUG(message, ...) log_message(LOG_DEBUG, __FILE__, __LINE__, message, ##__VA_ARGS__)
#else
  #define LOG_DEBUG(message, ...) VOID_PROC
#endif // DEBUG
       //
#define LOG_INFO(message, ...) log_message(LOG_INFO, __FILE__, __LINE__, message, ##__VA_ARGS__)

// Just a little wrapper, don't have to && your message, and complains if you don't
// give it a message, which is good practice and probably ought to force myself to do it
#ifdef DEBUG
  #define ASSERT(expr, message) assert(expr && message)
#else
  #define ASSERT(expr, message) VOID_PROC
#endif // DEBUG

/////////////////
// MEMORY ARENA
////////////////
typedef enum Arena_Flags
{
  ARENA_FLAG_NONE          = 0,
  ARENA_FLAG_BUFFER_BACKED = 1 << 0, // Made with a provided backing buffer, therefore not responsible for freeing backing
}
Arena_Flags;

typedef struct Arena Arena;
struct Arena
{
  u8    *base;
  isize capacity;
  isize next_offset;

  Arena_Flags flags;
};

#define EXT_ARENA_ALLOCATION 0xffffffff

// Allocates it's own memory
Arena arena_make(isize reserve_size);
Arena arena_make_backed(u8 *backing_buffer, isize backing_size);

void arena_free(Arena *arena);

void *arena_alloc(Arena *arena, isize size, isize alignment);
void arena_pop_to(Arena *arena, isize offset);
void arena_pop(Arena *arena, isize size);
void arena_clear(Arena *arena);

// Reads the entire thing and returns a String (just a byte slice)
String read_file_to_arena(Arena *arena, const char *name);

// Helper Macros ----------------------------------------------------------------

// specify the arena, the number of elements, and the type... c(ounted)alloc
#define arena_calloc(b, count, T) (T *)arena_alloc((b), sizeof(T) * (count), alignof(T))

// Useful for structs, much like new in other languages
#define arena_new(b, T) arena_calloc(b, 1, T)

// Scratch Use Case -------------------------------------------------------------

// We just want some temporary memory
// ie we save the offset we wish to return to after using this arena as a scratch pad
typedef struct Scratch Scratch;
struct Scratch
{
  Arena *arena;
  isize offset_save;
};

Scratch scratch_begin(Arena *arena);
void scratch_end(Scratch *scratch);

#ifdef __cplusplus
} // extern "C"
#endif

// C++ Garbage
#ifdef __cplusplus

// Bounds checked array with length info embedded
template <typename T, isize N>
struct Array
{
  T data[N];

  static constexpr isize count() { return N; }

  // Access
  T& operator[](isize i)
  {
    ASSERT(i < N, "Array bounds check index greater than count");
    return data[i];
  }
  const T& operator[](isize i) const
  {
    ASSERT(i < N, "Array bounds check index greater than count");
    return data[i];
  }

  // Iteration
  T* begin() { return data; }
  T* end()   { return data + N; }
  const T* begin() const { return data; }
  const T* end()   const { return data + N; }
};

template <typename T>
struct Slice
{
  T     *data;
  isize count; // Don't modify it, obviously

  // Access
  T& operator[](isize i)
  {
    ASSERT(i < count, "Array bounds check index greater than count");
    return data[i];
  }
  const T& operator[](isize i) const
  {
    ASSERT(i < count, "Array bounds check index greater than count");
    return data[i];
  }

  // Iteration
  T* begin() { return data; }
  T* end()   { return data + count; }
  const T* begin() const { return data; }
  const T* end()   const { return data + count; }
};

// begin inclusive, end exclusive
template <typename T, isize N>
Slice<T> slice(Array<T, N> *array, isize begin, isize end)
{
  ASSERT(begin >= 0 && end <= array->count(), "Slice bounds must not lie outside backing array bounds");
  ASSERT(begin < end, "Slice begin must come before end");

  isize count = end - begin;

  Slice<T> slice = {};
  slice.data = &(*array)[begin];
  slice.count = count;

  return slice;
}
template <typename T>
Slice<T> slice(Slice<T> _slice, isize begin, isize end)
{
  ASSERT(begin >= 0 && end <= _slice.count, "Slice bounds must not lie outside backing array bounds");
  ASSERT(begin < end, "Slice begin must come before end");

  isize count = end - begin;

  Slice<T> slice = {};
  slice.data = &_slice.data[begin];
  slice.count = count;

  return slice;
}

// Acts like a dynamic array, append, pop, etc but is backed by a statically sized array
template <typename T, isize N>
struct Bump_Array
{
  T     data[N];
  isize count;

  static constexpr isize capacity() { return N; }

  // Access
  T& operator[](isize i)
  {
    ASSERT(i < count, "Array bounds check index greater than count");
    return data[i];
  }
  const T& operator[](isize i) const
  {
    ASSERT(i < count, "Array bounds check index greater than count");
    return data[i];
  }

  // Iteration
  T* begin() { return data; }
  T* end()   { return data + count; }
  const T* begin() const { return data; }
  const T* end()   const { return data + count; }
};

template <typename T, isize N>
void bump_array_add(Bump_Array<T, N> *array, T item)
{
  ASSERT(array->count < N, "Bump Array is full!");

  array->data[array->count] = item;
  array->count += 1;
}

template <typename T, isize N>
void bump_array_pop(Bump_Array<T, N> *array)
{
  ZERO_SIZE(&array->data[array->count - 1], sizeof(T));
  array->count -= 1;
}

#endif // __cplusplus C++ Garbage

/////////////////
// IMPLEMENT
////////////////
// #define COMMON_IMPLEMENTATION
#ifdef COMMON_IMPLEMENTATION
// Returns size of file, or 0 if it can't open the file
usize read_file_to_memory(const char *name, u8 *buffer, usize buffer_size)
{
  FILE *file = fopen(name, "rb");
  if (file == NULL)
  {
    LOG_ERROR("Unable to open file: %s", name);
    return 0;
  }

  usize byte_count = fread(buffer, sizeof(u8), buffer_size, file);
  fclose(file);

  return byte_count;
}

usize file_size(const char *name)
{
  // Seriously???
#if _WIN32
  struct __stat64 stats;
  _stat64(name, &stats);
#else
  struct stat stats;
  stat(name, &stats);
#endif

  return stats.st_size;
}

String read_file_to_arena(Arena *arena, const char *name)
{
  usize buffer_size = file_size(name);

  // Just in case we fail reading we won't commit any allocations
  Arena save = *arena;
  u8 *buffer = arena_calloc(arena, buffer_size, u8);

  if (read_file_to_memory(name, buffer, buffer_size) != buffer_size)
  {
    LOG_ERROR("Unable to read file: %s", name);
    *arena = save; // Rollback allocation
  }

  String result =
  {
    .data  = buffer,
    .count = buffer_size,
  };

  return result;
}

b8 strings_equal(String a, String b)
{
  return a.count == b.count && memcmp(a.data, b.data, a.count) == 0;
}

#ifndef LOG_TITLE
#define LOG_TITLE "COMMON"
#endif
const char *level_strings[] =
{
  LOG_ENUM(ENUM_STRING)
};

void log_message(Log_Level level, const char *file, usize line, const char *message, ...)
{
  FILE *stream = stderr;
  if (level <= LOG_ERROR)
  {
    fprintf(stream, "[" LOG_TITLE " %s]: (%s:%lu) ", level_strings[level], file, line);
  }
  else
  {
    if (level == LOG_INFO)
    {
      stream = stdout;
    }
    fprintf(stream, "[" LOG_TITLE " %s]: ", level_strings[level]);
  }

  va_list args;
  va_start(args, message);
  vfprintf(stream, message, args);
  va_end(args);

  fprintf(stream, "\n");
}

Arena arena_make(isize reserve_size)
{
  Arena arena = {0};

  // NOTE(ss): Calloc will return page-aligned memory so I don't think it is
  // necessary to make sure that the alignment suffices
  arena.base = (u8 *)calloc(reserve_size, 1);

  if (arena.base == NULL)
  {
    LOG_FATAL("Failed to allocate arena memory", EXT_ARENA_ALLOCATION);
    return arena;
  }

  arena.capacity = reserve_size;
  arena.next_offset = 0;

  return arena;
}

Arena arena_make_backed(u8 *backing_buffer, isize backing_size)
{
  ASSERT(backing_buffer != NULL, "Backing buffer for arena must not be NULL!");
  ASSERT(backing_size   != 0,    "Backing buffer size for arena must not be 0!");

  Arena arena = {0};

  arena.base     = backing_buffer;
  arena.capacity = backing_size;

  // Shitty cpp compilers complain we don't do it like this
  arena.flags = (Arena_Flags)(arena.flags | ARENA_FLAG_BUFFER_BACKED);

  return arena;
}

void arena_free(Arena *arena)
{
  if (!(arena->flags & ARENA_FLAG_BUFFER_BACKED))
  {
    free(arena->base);
  }

  ZERO_STRUCT(arena);
}

void *arena_alloc(Arena *arena, isize size, isize alignment) {
  ASSERT(arena->base != NULL, "Arena memory is null");

  isize aligned_offset = ALIGN_ROUND_UP(arena->next_offset, alignment);

  // Do we need a bigger buffer?
  if ((aligned_offset + size) > arena->capacity)
  {
    u64 needed_capacity = aligned_offset + size;

    LOG_FATAL("Not enough memory in arena, NEED: %ld bytes HAVE: %ld bytes",
              EXT_ARENA_ALLOCATION, needed_capacity, arena->capacity);
    return NULL;
  }

  void *ptr = arena->base + aligned_offset;
  ZERO_SIZE(ptr, size); // make sure memory is zeroed out

  // now move the offset
  arena->next_offset = aligned_offset + size;

  return ptr;
}

void arena_pop_to(Arena *arena, isize offset)
{
  ASSERT(offset < arena->next_offset,
         "Failed to pop arena allocation, more than currently allocated");

  // Should we zero out the memory?
  arena->next_offset = offset;
}

void arena_pop(Arena *arena, isize size)
{
  arena_pop_to(arena, arena->next_offset - size);
}

void arena_clear(Arena *arena)
{
  arena->next_offset = 0;
}

Scratch scratch_begin(Arena *arena)
{
  Scratch scratch = {.arena = arena, .offset_save = arena->next_offset};
  return scratch;
}

void scratch_end(Scratch *scratch)
{
  arena_pop_to(scratch->arena, scratch->offset_save);
  ZERO_STRUCT(scratch);
}

#endif // COMMON_IMPLEMENTATION

#endif // COMMON_H
