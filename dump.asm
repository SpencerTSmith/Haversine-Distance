
calc.x:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	endbr64
    1004:	sub    rsp,0x8
    1008:	mov    rax,QWORD PTR [rip+0x3fb9]        # 4fc8 <__gmon_start__@Base>
    100f:	test   rax,rax
    1012:	je     1016 <_init+0x16>
    1014:	call   rax
    1016:	add    rsp,0x8
    101a:	ret

Disassembly of section .plt:

0000000000001020 <free@plt-0x10>:
    1020:	push   QWORD PTR [rip+0x3fca]        # 4ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	jmp    QWORD PTR [rip+0x3fcc]        # 4ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	nop    DWORD PTR [rax+0x0]

0000000000001030 <free@plt>:
    1030:	jmp    QWORD PTR [rip+0x3fca]        # 5000 <free@GLIBC_2.2.5>
    1036:	push   0x0
    103b:	jmp    1020 <_init+0x20>

0000000000001040 <fread@plt>:
    1040:	jmp    QWORD PTR [rip+0x3fc2]        # 5008 <fread@GLIBC_2.2.5>
    1046:	push   0x1
    104b:	jmp    1020 <_init+0x20>

0000000000001050 <fclose@plt>:
    1050:	jmp    QWORD PTR [rip+0x3fba]        # 5010 <fclose@GLIBC_2.2.5>
    1056:	push   0x2
    105b:	jmp    1020 <_init+0x20>

0000000000001060 <__stack_chk_fail@plt>:
    1060:	jmp    QWORD PTR [rip+0x3fb2]        # 5018 <__stack_chk_fail@GLIBC_2.4>
    1066:	push   0x3
    106b:	jmp    1020 <_init+0x20>

0000000000001070 <printf@plt>:
    1070:	jmp    QWORD PTR [rip+0x3faa]        # 5020 <printf@GLIBC_2.2.5>
    1076:	push   0x4
    107b:	jmp    1020 <_init+0x20>

0000000000001080 <gettimeofday@plt>:
    1080:	jmp    QWORD PTR [rip+0x3fa2]        # 5028 <gettimeofday@GLIBC_2.2.5>
    1086:	push   0x5
    108b:	jmp    1020 <_init+0x20>

0000000000001090 <__assert_fail@plt>:
    1090:	jmp    QWORD PTR [rip+0x3f9a]        # 5030 <__assert_fail@GLIBC_2.2.5>
    1096:	push   0x6
    109b:	jmp    1020 <_init+0x20>

00000000000010a0 <memset@plt>:
    10a0:	jmp    QWORD PTR [rip+0x3f92]        # 5038 <memset@GLIBC_2.2.5>
    10a6:	push   0x7
    10ab:	jmp    1020 <_init+0x20>

00000000000010b0 <cos@plt>:
    10b0:	jmp    QWORD PTR [rip+0x3f8a]        # 5040 <cos@GLIBC_2.2.5>
    10b6:	push   0x8
    10bb:	jmp    1020 <_init+0x20>

00000000000010c0 <fputc@plt>:
    10c0:	jmp    QWORD PTR [rip+0x3f82]        # 5048 <fputc@GLIBC_2.2.5>
    10c6:	push   0x9
    10cb:	jmp    1020 <_init+0x20>

00000000000010d0 <memcmp@plt>:
    10d0:	jmp    QWORD PTR [rip+0x3f7a]        # 5050 <memcmp@GLIBC_2.2.5>
    10d6:	push   0xa
    10db:	jmp    1020 <_init+0x20>

00000000000010e0 <calloc@plt>:
    10e0:	jmp    QWORD PTR [rip+0x3f72]        # 5058 <calloc@GLIBC_2.2.5>
    10e6:	push   0xb
    10eb:	jmp    1020 <_init+0x20>

00000000000010f0 <fprintf@plt>:
    10f0:	jmp    QWORD PTR [rip+0x3f6a]        # 5060 <fprintf@GLIBC_2.2.5>
    10f6:	push   0xc
    10fb:	jmp    1020 <_init+0x20>

0000000000001100 <stat@plt>:
    1100:	jmp    QWORD PTR [rip+0x3f62]        # 5068 <stat@GLIBC_2.33>
    1106:	push   0xd
    110b:	jmp    1020 <_init+0x20>

0000000000001110 <fopen@plt>:
    1110:	jmp    QWORD PTR [rip+0x3f5a]        # 5070 <fopen@GLIBC_2.2.5>
    1116:	push   0xe
    111b:	jmp    1020 <_init+0x20>

0000000000001120 <vfprintf@plt>:
    1120:	jmp    QWORD PTR [rip+0x3f52]        # 5078 <vfprintf@GLIBC_2.2.5>
    1126:	push   0xf
    112b:	jmp    1020 <_init+0x20>

0000000000001130 <sin@plt>:
    1130:	jmp    QWORD PTR [rip+0x3f4a]        # 5080 <sin@GLIBC_2.2.5>
    1136:	push   0x10
    113b:	jmp    1020 <_init+0x20>

0000000000001140 <asin@plt>:
    1140:	jmp    QWORD PTR [rip+0x3f42]        # 5088 <asin@GLIBC_2.2.5>
    1146:	push   0x11
    114b:	jmp    1020 <_init+0x20>

0000000000001150 <exit@plt>:
    1150:	jmp    QWORD PTR [rip+0x3f3a]        # 5090 <exit@GLIBC_2.2.5>
    1156:	push   0x12
    115b:	jmp    1020 <_init+0x20>

0000000000001160 <sqrt@plt>:
    1160:	jmp    QWORD PTR [rip+0x3f32]        # 5098 <sqrt@GLIBC_2.2.5>
    1166:	push   0x13
    116b:	jmp    1020 <_init+0x20>

Disassembly of section .text:

0000000000001180 <parser_at.part.0>:
  String source;
  usize  at;
};

static
u8 *parser_at(JSON_Parser *parser)
    1180:	push   rax
{
  ASSERT(parser->at < parser->source.count, "Attempted to read past parser source");
    1181:	lea    rcx,[rip+0x2790]        # 3918 <__PRETTY_FUNCTION__.6>
    1188:	mov    edx,0x2f
    118d:	lea    rsi,[rip+0x1e70]        # 3004 <_IO_stdin_used+0x4>
    1194:	lea    rdi,[rip+0x2075]        # 3210 <_IO_stdin_used+0x210>
    119b:	call   1090 <__assert_fail@plt>

00000000000011a0 <arena_pop_to.part.0>:
  arena->next_offset = aligned_offset + size;

  return ptr;
}

void arena_pop_to(Arena *arena, isize offset)
    11a0:	push   rax
{
  ASSERT(offset < arena->next_offset,
    11a1:	lea    rcx,[rip+0x2780]        # 3928 <__PRETTY_FUNCTION__.7>
    11a8:	mov    edx,0x217
    11ad:	lea    rsi,[rip+0x1e61]        # 3015 <_IO_stdin_used+0x15>
    11b4:	lea    rdi,[rip+0x20a5]        # 3260 <_IO_stdin_used+0x260>
    11bb:	call   1090 <__assert_fail@plt>

00000000000011c0 <arena_make_backed.cold>:
  ASSERT(backing_buffer != NULL, "Backing buffer for arena must not be NULL!");
    11c0:	lea    rcx,[rip+0x2789]        # 3950 <__PRETTY_FUNCTION__.9>
    11c7:	mov    edx,0x1e5
    11cc:	lea    rsi,[rip+0x1e42]        # 3015 <_IO_stdin_used+0x15>
    11d3:	lea    rdi,[rip+0x2106]        # 32e0 <_IO_stdin_used+0x2e0>
    11da:	call   1090 <__assert_fail@plt>
  ASSERT(backing_size   != 0,    "Backing buffer size for arena must not be 0!");
    11df:	lea    rcx,[rip+0x276a]        # 3950 <__PRETTY_FUNCTION__.9>
    11e6:	mov    edx,0x1e6
    11eb:	lea    rsi,[rip+0x1e23]        # 3015 <_IO_stdin_used+0x15>
    11f2:	lea    rdi,[rip+0x2137]        # 3330 <_IO_stdin_used+0x330>
    11f9:	call   1090 <__assert_fail@plt>

00000000000011fe <arena_alloc.cold>:
  ASSERT(arena->base != NULL, "Arena memory is null");
    11fe:	lea    rcx,[rip+0x2733]        # 3938 <__PRETTY_FUNCTION__.8>
    1205:	mov    edx,0x1fe
    120a:	lea    rsi,[rip+0x1e04]        # 3015 <_IO_stdin_used+0x15>
    1211:	lea    rdi,[rip+0x2160]        # 3378 <_IO_stdin_used+0x378>
    1218:	call   1090 <__assert_fail@plt>

000000000000121d <arena_pop_to.cold>:
{
    121d:	push   rax
    121e:	call   11a0 <arena_pop_to.part.0>

0000000000001223 <arena_pop.cold>:
  // Should we zero out the memory?
  arena->next_offset = offset;
}

void arena_pop(Arena *arena, isize size)
{
    1223:	push   rax
    1224:	call   11a0 <arena_pop_to.part.0>

0000000000001229 <scratch_end.cold>:
  Scratch scratch = {.arena = arena, .offset_save = arena->next_offset};
  return scratch;
}

void scratch_end(Scratch *scratch)
{
    1229:	push   rax
    122a:	call   11a0 <arena_pop_to.part.0>

000000000000122f <get_json_token.cold>:
    122f:	call   1180 <parser_at.part.0>

0000000000001234 <json_object_to_f64.cold>:

  return result;
}

f64 json_object_to_f64(JSON_Object *object)
{
    1234:	push   rax
  ASSERT(object, "Must pass valid object to f64 conversion");
    1235:	lea    rcx,[rip+0x26c4]        # 3900 <__PRETTY_FUNCTION__.5>
    123c:	mov    edx,0x1c2
    1241:	lea    rsi,[rip+0x1dbc]        # 3004 <_IO_stdin_used+0x4>
    1248:	lea    rdi,[rip+0x22a9]        # 34f8 <_IO_stdin_used+0x4f8>
    124f:	call   1090 <__assert_fail@plt>
    1254:	cs nop WORD PTR [rax+rax*1+0x0]
    125e:	xchg   ax,ax

0000000000001260 <main>:

  return (fabs(a) - fabs(b)) <= epsilon;
}

int main(int args_count, char **args)
{
    1260:	push   r15
    1262:	push   r14
    1264:	push   r13
    1266:	push   r12
    1268:	push   rbp
    1269:	push   rbx
    126a:	sub    rsp,0x1c8
    1271:	mov    QWORD PTR [rsp+0x30],rsi
    1276:	mov    rax,QWORD PTR fs:0x28
    127f:	mov    QWORD PTR [rsp+0x1b8],rax
    1287:	xor    eax,eax
  if (args_count != DESIRED_ARG_COUNT)
    1289:	cmp    edi,0x3
    128c:	je     12cd <main+0x6d>
  {
    printf("Usage: %s [haversine_json] [solution_dump]\n", args[0]);
    128e:	mov    rsi,QWORD PTR [rsi]
    1291:	lea    rdi,[rip+0x2298]        # 3530 <_IO_stdin_used+0x530>
    1298:	xor    eax,eax
    129a:	call   1070 <printf@plt>
    return 1;
    129f:	mov    eax,0x1
  {
    arena_free(&arena);
  }

  end_profiling();
}
    12a4:	mov    rdx,QWORD PTR [rsp+0x1b8]
    12ac:	sub    rdx,QWORD PTR fs:0x28
    12b5:	jne    1d03 <main+0xaa3>
    12bb:	add    rsp,0x1c8
    12c2:	pop    rbx
    12c3:	pop    rbp
    12c4:	pop    r12
    12c6:	pop    r13
    12c8:	pop    r14
    12ca:	pop    r15
    12cc:	ret
/* rdtsc */
extern __inline unsigned long long
__attribute__((__gnu_inline__, __always_inline__, __artificial__))
__rdtsc (void)
{
  return __builtin_ia32_rdtsc ();
    12cd:	rdtsc
static Profiler g_profiler;

static
void begin_profiling()
{
  g_profiler = (Profiler)
    12cf:	xor    esi,esi
    12d1:	lea    rdi,[rip+0x3e48]        # 5120 <g_profiler>
    12d8:	shl    rdx,0x20
    12dc:	mov    rbx,rax
    12df:	or     rbx,rdx
    12e2:	mov    edx,0x28010
    12e7:	call   10a0 <memset@plt>
  Arena arena = {0};
    12ec:	xor    eax,eax
    12ee:	mov    ecx,0x8
    12f3:	lea    rdi,[rsp+0xa0]
    12fb:	rep stos DWORD PTR [rdi],eax
  arena = arena_make(GB(4));
    12fd:	mov    esi,0x1
    1302:	lea    rdi,[rsp+0x50]
    1307:	mov    QWORD PTR [rip+0x3e12],rbx        # 5120 <g_profiler>
    130e:	shl    rsi,0x20
    1312:	call   2190 <arena_make>
    1317:	movdqu xmm0,XMMWORD PTR [rsp+0x50]
    .zone_index   = zone_index,
    .old_elapsed_inclusive = g_profiler.zones[zone_index].elapsed_inclusive, // Save the original so it get overwritten in the case of children
  };

  // Push parent
  g_profiler.current_parent_zone = zone_index;
    131d:	mov    QWORD PTR [rip+0x3e00],0x5        # 5128 <g_profiler+0x8>
    1328:	movaps XMMWORD PTR [rsp+0xa0],xmm0
    1330:	movdqu xmm0,XMMWORD PTR [rsp+0x60]
    1336:	movaps XMMWORD PTR [rsp+0xb0],xmm0
    133e:	rdtsc

  // Make sure this is the last thing to run
  pass.start = read_cpu_timer();

  return pass;
    1340:	lea    rcx,[rip+0x1d39]        # 3080 <_IO_stdin_used+0x80>
    1347:	shl    rdx,0x20
    source = read_file_to_arena(&arena, args[1]);
    134b:	lea    r15,[rsp+0xa0]
    1353:	mov    QWORD PTR [rsp+0xc0],rcx
    135b:	or     rax,rdx
    135e:	mov    rdi,r15
    1361:	xor    edx,edx
    1363:	mov    QWORD PTR [rsp+0xc8],0x4
    136f:	mov    QWORD PTR [rsp+0xd0],rax
    1377:	xor    eax,eax
    1379:	mov    QWORD PTR [rsp+0xd8],rax
    1381:	mov    rax,QWORD PTR [rsp+0x30]
    1386:	mov    QWORD PTR [rsp+0xe0],0x5
    1392:	mov    rsi,QWORD PTR [rax+0x8]
    1396:	mov    QWORD PTR [rsp+0xe8],rdx
    139e:	mov    QWORD PTR [rsp+0x38],r15
    13a3:	call   22f0 <read_file_to_arena>
  PROFILE_SCOPE("read")
    13a8:	sub    rsp,0x30
    13ac:	mov    ecx,0xc
    13b1:	lea    rsi,[rsp+0xf0]
    13b9:	mov    rdi,rsp
    source = read_file_to_arena(&arena, args[1]);
    13bc:	mov    rbx,rax
    13bf:	mov    rbp,rdx
  PROFILE_SCOPE("read")
    13c2:	rep movs DWORD PTR [rdi],DWORD PTR [rsi]
    13c4:	call   1e40 <__profile_end_pass>
    .parent_index = g_profiler.current_parent_zone,
    13c9:	mov    rcx,QWORD PTR [rip+0x3d58]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    13d0:	mov    QWORD PTR [rip+0x3d4d],0x6        # 5128 <g_profiler+0x8>
    13db:	rdtsc
  return pass;
    13dd:	lea    rdi,[rip+0x1ca1]        # 3085 <_IO_stdin_used+0x85>
    13e4:	shl    rdx,0x20
    13e8:	mov    QWORD PTR [rsp+0x148],rcx
    max_pairs = source.count / min_pair_bytes; // Roughly, overestimate at least
    13f0:	mov    ecx,0x18
    13f5:	or     rax,rdx
    13f8:	xor    edx,edx
    13fa:	mov    QWORD PTR [rsp+0x120],rdi
    pairs = arena_calloc(&arena, max_pairs, Haversine_Pair);
    1402:	mov    rdi,r15
    1405:	movq   xmm0,rax
    max_pairs = source.count / min_pair_bytes; // Roughly, overestimate at least
    140a:	mov    rax,rbp
    140d:	movhps xmm0,QWORD PTR [rip+0x3e24]        # 5238 <g_profiler+0x118>
    1414:	mov    QWORD PTR [rsp+0x128],0xf
    1420:	div    rcx
    1423:	movaps XMMWORD PTR [rsp+0x130],xmm0
    142b:	mov    QWORD PTR [rsp+0x140],0x6
    pairs = arena_calloc(&arena, max_pairs, Haversine_Pair);
    1437:	mov    edx,0x8
    143c:	add    rsp,0x30
    1440:	mov    rsi,rax
    max_pairs = source.count / min_pair_bytes; // Roughly, overestimate at least
    1443:	mov    r12,rax
    pairs = arena_calloc(&arena, max_pairs, Haversine_Pair);
    1446:	shl    rsi,0x5
    144a:	call   2270 <arena_alloc>
  PROFILE_SCOPE("haversine alloc")
    144f:	mov    ecx,0xc
    pairs = arena_calloc(&arena, max_pairs, Haversine_Pair);
    1454:	mov    QWORD PTR [rsp+0x20],rax
  PROFILE_SCOPE("haversine alloc")
    1459:	sub    rsp,0x30
    pairs = arena_calloc(&arena, max_pairs, Haversine_Pair);
    145d:	mov    r14,rax
  PROFILE_SCOPE("haversine alloc")
    1460:	lea    rsi,[rsp+0x120]
    1468:	mov    rdi,rsp
    146b:	rep movs DWORD PTR [rdi],DWORD PTR [rsi]
    146d:	call   1e40 <__profile_end_pass>
    .parent_index = g_profiler.current_parent_zone,
    1472:	mov    rcx,QWORD PTR [rip+0x3caf]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    1479:	mov    QWORD PTR [rip+0x3ca4],0x3        # 5128 <g_profiler+0x8>
    1484:	rdtsc
  return pass;
    1486:	lea    rdi,[rip+0x245b]        # 38e8 <__func__.4>
    148d:	shl    rdx,0x20
    1491:	mov    QWORD PTR [rsp+0x1d8],rcx
  JSON_Parser parser =
    1499:	xor    ecx,ecx
    149b:	or     rax,rdx
    149e:	mov    QWORD PTR [rsp+0x1b0],rdi
  JSON_Object *outer = parse_json_object(arena, &parser, (String){0}, get_json_token(&parser));
    14a6:	lea    rdi,[rsp+0xb0]
  JSON_Parser parser =
    14ae:	mov    QWORD PTR [rsp+0x180],rbx
    14b6:	movq   xmm0,rax
    14bb:	movhps xmm0,QWORD PTR [rip+0x3cfe]        # 51c0 <g_profiler+0xa0>
    14c2:	mov    QWORD PTR [rsp+0x190],rcx
    14ca:	movaps XMMWORD PTR [rsp+0x1c0],xmm0
    14d2:	mov    QWORD PTR [rsp+0x1b8],0xa
    14de:	mov    QWORD PTR [rsp+0x1d0],0x3
    14ea:	mov    QWORD PTR [rsp+0x188],rbp
  JSON_Object *outer = parse_json_object(arena, &parser, (String){0}, get_json_token(&parser));
    14f2:	add    rsp,0x30
    14f6:	lea    rbx,[rsp+0x150]
    14fe:	mov    rsi,rbx
    1501:	mov    QWORD PTR [rsp+0x48],rbx
    1506:	call   2440 <get_json_token>
    150b:	sub    rsp,0x20
    150f:	mov    rsi,rbx
    1512:	xor    edx,edx
    1514:	movdqa xmm0,XMMWORD PTR [rsp+0xa0]
    151d:	mov    rax,QWORD PTR [rsp+0xb0]
    1525:	xor    ecx,ecx
    1527:	mov    rdi,r15
    152a:	movups XMMWORD PTR [rsp],xmm0
    152e:	mov    QWORD PTR [rsp+0x10],rax
    1533:	call   2a60 <parse_json_object>
  profile_end_func();
    1538:	mov    ecx,0xc
    153d:	push   rsi
  JSON_Object *outer = parse_json_object(arena, &parser, (String){0}, get_json_token(&parser));
    153e:	mov    r9,rax
  profile_end_func();
    1541:	push   rsi
    1542:	lea    rsi,[rsp+0x1b0]
    154a:	mov    rdi,rsp
    154d:	mov    QWORD PTR [rsp+0x70],rsi
    1552:	rep movs DWORD PTR [rdi],DWORD PTR [rsi]
    1554:	call   1e40 <__profile_end_pass>
  JSON_Object *pairs_object = lookup_json_object(root, String("pairs"));
    1559:	add    rsp,0x30
    155d:	mov    edx,0x5
    1562:	mov    rdi,r9
    1565:	lea    rsi,[rip+0x1b29]        # 3095 <_IO_stdin_used+0x95>
    156c:	call   1ea0 <lookup_json_object>
    for (JSON_Object *cursor = pairs_object->first_child; cursor && pair_count < max_pairs; cursor = cursor->next_sibling)
    1571:	mov    rbx,QWORD PTR [rax+0x20]
    1575:	test   rbx,rbx
    1578:	je     1c8b <main+0xa2b>
    157e:	cmp    rbp,0x17
    1582:	jbe    1c8b <main+0xa2b>
    1588:	mov    rbp,r14
    158b:	mov    r15d,0x1
    1591:	lea    r13,[rip+0x1b03]        # 309b <_IO_stdin_used+0x9b>
    1598:	nop    DWORD PTR [rax+rax*1+0x0]
    .old_elapsed_inclusive = g_profiler.zones[zone_index].elapsed_inclusive, // Save the original so it get overwritten in the case of children
    15a0:	lea    rax,[rip+0x3b79]        # 5120 <g_profiler>
    15a7:	mov    rcx,QWORD PTR [rax+0x140]
    .parent_index = g_profiler.current_parent_zone,
    15ae:	mov    rsi,QWORD PTR [rax+0x8]
  g_profiler.current_parent_zone = zone_index;
    15b2:	mov    QWORD PTR [rip+0x3b6b],0x7        # 5128 <g_profiler+0x8>
    .old_elapsed_inclusive = g_profiler.zones[zone_index].elapsed_inclusive, // Save the original so it get overwritten in the case of children
    15bd:	mov    QWORD PTR [rsp+0x8],rcx
    15c2:	rdtsc
    15c4:	shl    rdx,0x20
  return pass;
    15c8:	mov    QWORD PTR [rsp+0x1a8],rsi
          .x0 = json_object_to_f64(lookup_json_object(cursor, String("x0"))),
    15d0:	mov    rdi,rbx
    15d3:	lea    rsi,[rip+0x1acf]        # 30a9 <_IO_stdin_used+0xa9>
    15da:	or     rax,rdx
    15dd:	mov    edx,0x2
    15e2:	mov    QWORD PTR [rsp+0x180],r13
    15ea:	mov    QWORD PTR [rsp+0x188],0xd
    15f6:	movq   xmm0,rax
    15fb:	movhps xmm0,QWORD PTR [rsp+0x8]
    1600:	mov    QWORD PTR [rsp+0x1a0],0x7
    160c:	movaps XMMWORD PTR [rsp+0x190],xmm0
    1614:	call   1ea0 <lookup_json_object>
    1619:	mov    rdi,rax
    161c:	call   2be0 <json_object_to_f64>
          .y0 = json_object_to_f64(lookup_json_object(cursor, String("y0"))),
    1621:	lea    rsi,[rip+0x1a84]        # 30ac <_IO_stdin_used+0xac>
    1628:	mov    edx,0x2
    162d:	mov    rdi,rbx
          .x0 = json_object_to_f64(lookup_json_object(cursor, String("x0"))),
    1630:	movsd  QWORD PTR [rsp+0x8],xmm0
          .y0 = json_object_to_f64(lookup_json_object(cursor, String("y0"))),
    1636:	call   1ea0 <lookup_json_object>
    163b:	mov    rdi,rax
    163e:	call   2be0 <json_object_to_f64>
    1643:	movsd  xmm1,QWORD PTR [rsp+0x8]
          .x1 = json_object_to_f64(lookup_json_object(cursor, String("x1"))),
    1649:	mov    edx,0x2
    164e:	mov    rdi,rbx
    1651:	lea    rsi,[rip+0x1a57]        # 30af <_IO_stdin_used+0xaf>
    1658:	unpcklpd xmm1,xmm0
    165c:	movaps XMMWORD PTR [rsp+0x10],xmm1
    1661:	call   1ea0 <lookup_json_object>
    1666:	mov    rdi,rax
    1669:	call   2be0 <json_object_to_f64>
          .y1 = json_object_to_f64(lookup_json_object(cursor, String("y1"))),
    166e:	lea    rsi,[rip+0x1a3d]        # 30b2 <_IO_stdin_used+0xb2>
    1675:	mov    edx,0x2
    167a:	mov    rdi,rbx
          .x1 = json_object_to_f64(lookup_json_object(cursor, String("x1"))),
    167d:	movsd  QWORD PTR [rsp+0x8],xmm0
          .y1 = json_object_to_f64(lookup_json_object(cursor, String("y1"))),
    1683:	call   1ea0 <lookup_json_object>
    1688:	mov    rdi,rax
    168b:	call   2be0 <json_object_to_f64>
        pairs[pair_count] = pair;
    1690:	movsd  xmm4,QWORD PTR [rsp+0x8]
    1696:	movapd xmm1,XMMWORD PTR [rsp+0x10]
      PROFILE_SCOPE("child convert")
    169c:	sub    rsp,0x30
        pairs[pair_count] = pair;
    16a0:	unpcklpd xmm4,xmm0
    16a4:	movups XMMWORD PTR [rbp+0x0],xmm1
      PROFILE_SCOPE("child convert")
    16a8:	movdqa xmm0,XMMWORD PTR [rsp+0x1b0]
        pairs[pair_count] = pair;
    16b1:	movups XMMWORD PTR [rbp+0x10],xmm4
      PROFILE_SCOPE("child convert")
    16b5:	movups XMMWORD PTR [rsp],xmm0
    16b9:	movdqa xmm0,XMMWORD PTR [rsp+0x1c0]
    16c2:	movups XMMWORD PTR [rsp+0x10],xmm0
    16c7:	movdqa xmm0,XMMWORD PTR [rsp+0x1d0]
    16d0:	movups XMMWORD PTR [rsp+0x20],xmm0
    16d5:	call   1e40 <__profile_end_pass>
    for (JSON_Object *cursor = pairs_object->first_child; cursor && pair_count < max_pairs; cursor = cursor->next_sibling)
    16da:	mov    rbx,QWORD PTR [rbx+0x28]
    16de:	add    rsp,0x30
    16e2:	mov    rsi,r15
    16e5:	test   rbx,rbx
    16e8:	setne  dl
    16eb:	cmp    r15,r12
    16ee:	setb   al
    16f1:	add    r15,0x1
    16f5:	add    rbp,0x20
    16f9:	test   dl,al
    16fb:	jne    15a0 <main+0x340>
    .parent_index = g_profiler.current_parent_zone,
    1701:	mov    rdi,QWORD PTR [rip+0x3a20]        # 5128 <g_profiler+0x8>
        pair_count += 1;
    1708:	mov    ebx,esi
  g_profiler.current_parent_zone = zone_index;
    170a:	mov    QWORD PTR [rip+0x3a13],0x8        # 5128 <g_profiler+0x8>
    1715:	rdtsc
  return pass;
    1717:	lea    rcx,[rip+0x1997]        # 30b5 <_IO_stdin_used+0xb5>
    171e:	mov    rbp,QWORD PTR [rsp+0x20]
    1723:	shl    rdx,0x20
    1727:	shl    rsi,0x5
    172b:	mov    QWORD PTR [rsp+0x120],rcx
    1733:	mov    QWORD PTR [rsp+0x148],rdi
    173b:	or     rax,rdx
    for (usize i = 0; i < pair_count; i++)
    173e:	add    rbp,rsi
  f64 sum = 0.0;
    1741:	mov    QWORD PTR [rsp+0x8],0x0
    174a:	movq   xmm0,rax
    174f:	movhps xmm0,QWORD PTR [rip+0x3b32]        # 5288 <g_profiler+0x168>
    1756:	mov    QWORD PTR [rsp+0x128],0x3
    1762:	mov    QWORD PTR [rsp+0x140],0x8
    176e:	movaps XMMWORD PTR [rsp+0x130],xmm0
    1776:	cs nop WORD PTR [rax+rax*1+0x0]
      f64 result = reference_haversine(pairs[i].x0,pairs[i].y0,pairs[i].x1,pairs[i].y1, earth_radius);
    1780:	movsd  xmm1,QWORD PTR [r14+0x18]
    1786:	movsd  xmm3,QWORD PTR [r14+0x8]
  f64 lat1 = y0;
  f64 lat2 = y1;
  f64 lon1 = x0;
  f64 lon2 = x1;

  f64 d_lat = to_radians(lat2 - lat1);
    178c:	movapd xmm0,xmm1
    1790:	movsd  QWORD PTR [rsp+0x20],xmm1
    1796:	subsd  xmm0,xmm3
  return degrees / PI;
    179a:	divsd  xmm0,QWORD PTR [rip+0x21ee]        # 3990 <__PRETTY_FUNCTION__.9+0x40>
  f64 d_lat = to_radians(lat2 - lat1);
    17a2:	movsd  QWORD PTR [rsp+0x10],xmm3
  f64 d_lon = to_radians(lon2 - lon1);
  lat1 = to_radians(lat1);
  lat2 = to_radians(lat2);

  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    17a8:	mulsd  xmm0,QWORD PTR [rip+0x21e8]        # 3998 <__PRETTY_FUNCTION__.9+0x48>
    17b0:	call   1130 <sin@plt>
  return degrees / PI;
    17b5:	movsd  xmm3,QWORD PTR [rsp+0x10]
    17bb:	divsd  xmm3,QWORD PTR [rip+0x21cd]        # 3990 <__PRETTY_FUNCTION__.9+0x40>
  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    17c3:	movsd  QWORD PTR [rsp+0x28],xmm0
  return degrees / PI;
    17c9:	movapd xmm0,xmm3
  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    17cd:	call   10b0 <cos@plt>
  return degrees / PI;
    17d2:	movsd  xmm1,QWORD PTR [rsp+0x20]
    17d8:	divsd  xmm1,QWORD PTR [rip+0x21b0]        # 3990 <__PRETTY_FUNCTION__.9+0x40>
  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    17e0:	movsd  QWORD PTR [rsp+0x10],xmm0
  return degrees / PI;
    17e6:	movapd xmm0,xmm1
  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    17ea:	call   10b0 <cos@plt>
    17ef:	movsd  QWORD PTR [rsp+0x20],xmm0
  f64 d_lon = to_radians(lon2 - lon1);
    17f5:	movsd  xmm0,QWORD PTR [r14+0x10]
    17fb:	subsd  xmm0,QWORD PTR [r14]
  return degrees / PI;
    1800:	divsd  xmm0,QWORD PTR [rip+0x2188]        # 3990 <__PRETTY_FUNCTION__.9+0x40>
  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    1808:	mulsd  xmm0,QWORD PTR [rip+0x2188]        # 3998 <__PRETTY_FUNCTION__.9+0x48>
    1810:	call   1130 <sin@plt>
    1815:	movsd  xmm1,QWORD PTR [rsp+0x10]
    181b:	mulsd  xmm1,QWORD PTR [rsp+0x20]
    1821:	pxor   xmm7,xmm7
  return x * x;
    1825:	mulsd  xmm0,xmm0
    1829:	movsd  xmm2,QWORD PTR [rsp+0x28]
    182f:	mulsd  xmm2,xmm2
  f64 a = square(sin(d_lat/2.0)) + cos(lat1) * cos(lat2) * square(sin(d_lon/2.0));
    1833:	mulsd  xmm0,xmm1
    1837:	addsd  xmm0,xmm2
  f64 c = 2.0 * asin(sqrt(a));
    183b:	ucomisd xmm7,xmm0
    183f:	ja     1cf9 <main+0xa99>
    1845:	sqrtsd xmm0,xmm0
    1849:	call   1140 <asin@plt>
    for (usize i = 0; i < pair_count; i++)
    184e:	add    r14,0x20
    1852:	addsd  xmm0,xmm0

  f64 result = sphere_radius * c;
    1856:	mulsd  xmm0,QWORD PTR [rip+0x2142]        # 39a0 <__PRETTY_FUNCTION__.9+0x50>
      sum += result;
    185e:	addsd  xmm0,QWORD PTR [rsp+0x8]
    1864:	movsd  QWORD PTR [rsp+0x8],xmm0
    for (usize i = 0; i < pair_count; i++)
    186a:	cmp    rbp,r14
    186d:	jne    1780 <main+0x520>
  PROFILE_SCOPE("sum")
    1873:	sub    rsp,0x30
    1877:	mov    ecx,0xc
    187c:	lea    rsi,[rsp+0x150]
    1884:	mov    rdi,rsp
    1887:	rep movs DWORD PTR [rdi],DWORD PTR [rsi]
    1889:	call   1e40 <__profile_end_pass>
    .parent_index = g_profiler.current_parent_zone,
    188e:	mov    rcx,QWORD PTR [rip+0x3893]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    1895:	mov    QWORD PTR [rip+0x3888],0x9        # 5128 <g_profiler+0x8>
    18a0:	rdtsc
  return pass;
    18a2:	lea    rdi,[rip+0x1810]        # 30b9 <_IO_stdin_used+0xb9>
    18a9:	shl    rdx,0x20
    18ad:	mov    QWORD PTR [rsp+0x180],rdi
    18b5:	or     rax,rdx
    18b8:	mov    QWORD PTR [rsp+0x1a8],rcx
    18c0:	mov    QWORD PTR [rsp+0x188],0x5
    18cc:	movq   xmm0,rax
    18d1:	movhps xmm0,QWORD PTR [rip+0x39d8]        # 52b0 <g_profiler+0x190>
    18d8:	mov    QWORD PTR [rsp+0x1a0],0x9
    18e4:	movaps XMMWORD PTR [rsp+0x190],xmm0
    String solution_dump = read_file_to_arena(&arena, args[2]);
    18ec:	mov    rax,QWORD PTR [rsp+0x60]
    18f1:	add    rsp,0x30
    18f5:	mov    rdi,QWORD PTR [rsp+0x38]
    18fa:	mov    rsi,QWORD PTR [rax+0x10]
    18fe:	call   22f0 <read_file_to_arena>
    if (solution_dump.count >= sizeof(f64) + sizeof(i32))
    1903:	cmp    rdx,0xb
    1907:	jbe    1c19 <main+0x9b9>
      i32 solution_pairs = *(i32 *)(solution_dump.data + sizeof(f64));
    190d:	mov    r8d,DWORD PTR [rax+0x8]
      if (solution_pairs == pair_count)
    1911:	cmp    r8d,ebx
    1914:	jne    1c3d <main+0x9dd>
    sum /= pair_count;
    191a:	movsd  xmm1,QWORD PTR [rsp+0x8]
    1920:	pxor   xmm0,xmm0
      f64 solution_sum   = *(f64 *)solution_dump.data;
    1924:	movsd  xmm2,QWORD PTR [rax]
    sum /= pair_count;
    1928:	cvtsi2sd xmm0,ebx
    192c:	divsd  xmm1,xmm0
  return (fabs(a) - fabs(b)) <= epsilon;
    1930:	movapd xmm0,xmm2
    1934:	andpd  xmm0,XMMWORD PTR [rip+0x2084]        # 39c0 <__PRETTY_FUNCTION__.9+0x70>
    193c:	movapd xmm3,xmm1
    1940:	andpd  xmm3,XMMWORD PTR [rip+0x2078]        # 39c0 <__PRETTY_FUNCTION__.9+0x70>
    1948:	subsd  xmm0,xmm3
        if (epsilon_equal(solution_sum, sum))
    194c:	movsd  xmm3,QWORD PTR [rip+0x2054]        # 39a8 <__PRETTY_FUNCTION__.9+0x58>
    1954:	comisd xmm3,xmm0
          LOG_INFO("Solutions (solution: %f, calculated: %f) match! :)", solution_sum, sum);
    1958:	movapd xmm0,xmm2
        if (epsilon_equal(solution_sum, sum))
    195c:	jae    1ba3 <main+0x943>
          LOG_ERROR("Solution sum (%f) does not match calculated sum (%f)", solution_sum, sum);
    1962:	mov    edx,0x68
    1967:	mov    edi,0x1
    196c:	mov    eax,0x2
    1971:	lea    rcx,[rip+0x1c70]        # 35e8 <_IO_stdin_used+0x5e8>
    1978:	lea    rsi,[rip+0x1740]        # 30bf <_IO_stdin_used+0xbf>
    197f:	call   1ff0 <log_message>
  PROFILE_SCOPE("check")
    1984:	sub    rsp,0x30
    1988:	mov    ecx,0xc
    198d:	mov    rsi,QWORD PTR [rsp+0x78]
    1992:	mov    rdi,rsp
    1995:	rep movs DWORD PTR [rdi],DWORD PTR [rsi]
    1997:	call   1e40 <__profile_end_pass>
    .parent_index = g_profiler.current_parent_zone,
    199c:	mov    rcx,QWORD PTR [rip+0x3785]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    19a3:	mov    QWORD PTR [rip+0x377a],0xa        # 5128 <g_profiler+0x8>
    19ae:	rdtsc
  return pass;
    19b0:	lea    rdi,[rip+0x171d]        # 30d4 <_IO_stdin_used+0xd4>
    19b7:	shl    rdx,0x20
    19bb:	mov    QWORD PTR [rsp+0x1d8],rcx
    19c3:	or     rax,rdx
    19c6:	mov    QWORD PTR [rsp+0x1b0],rdi
    19ce:	movq   xmm0,rax
    19d3:	mov    QWORD PTR [rsp+0x1b8],0x4
    19df:	movhps xmm0,QWORD PTR [rip+0x38f2]        # 52d8 <g_profiler+0x1b8>
    19e6:	mov    QWORD PTR [rsp+0x1d0],0xa
    19f2:	movaps XMMWORD PTR [rsp+0x1c0],xmm0
    arena_free(&arena);
    19fa:	mov    rdi,QWORD PTR [rsp+0x68]
    19ff:	add    rsp,0x30
    1a03:	call   2230 <arena_free>
  PROFILE_SCOPE("free")
    1a08:	sub    rsp,0x30
    1a0c:	mov    ecx,0xc
    1a11:	mov    rsi,QWORD PTR [rsp+0x70]
    1a16:	mov    rdi,rsp
    1a19:	rep movs DWORD PTR [rdi],DWORD PTR [rsi]
    1a1b:	call   1e40 <__profile_end_pass>
    1a20:	rdtsc
    1a22:	shl    rdx,0x20
  if (total_delta)
    1a26:	add    rsp,0x30
    1a2a:	or     rax,rdx
    1a2d:	sub    rax,QWORD PTR [rip+0x36ec]        # 5120 <g_profiler>
    1a34:	mov    rbx,rax
    1a37:	jne    1a40 <main+0x7e0>
    1a39:	xor    eax,eax
    1a3b:	jmp    12a4 <main+0x44>
    1a40:	rdtsc
  gettimeofday(&value, 0);
    1a42:	xor    esi,esi
    1a44:	lea    r12,[rsp+0x70]
    1a49:	mov    r13,rax
    1a4c:	shl    rdx,0x20
    1a50:	mov    rdi,r12
    1a53:	or     r13,rdx
    1a56:	call   1080 <gettimeofday@plt>
  u64 result = get_os_timer_freq() * value.tv_sec + value.tv_usec;
    1a5b:	imul   rbp,QWORD PTR [rsp+0x70],0xf4240
    1a64:	add    rbp,QWORD PTR [rsp+0x78]
  while (os_delta < os_wait_time)
    1a69:	nop    DWORD PTR [rax+0x0]
  gettimeofday(&value, 0);
    1a70:	xor    esi,esi
    1a72:	mov    rdi,r12
    1a75:	call   1080 <gettimeofday@plt>
  u64 result = get_os_timer_freq() * value.tv_sec + value.tv_usec;
    1a7a:	imul   rcx,QWORD PTR [rsp+0x70],0xf4240
    1a83:	add    rcx,QWORD PTR [rsp+0x78]
    os_delta = os_end - os_start;
    1a88:	sub    rcx,rbp
  while (os_delta < os_wait_time)
    1a8b:	cmp    rcx,0x1869f
    1a92:	jbe    1a70 <main+0x810>
    1a94:	rdtsc
    1a96:	shl    rdx,0x20
    1a9a:	or     rax,rdx
  cpu_frequency = os_frequency * cpu_delta / os_delta;
    1a9d:	xor    edx,edx
  u64 cpu_delta = cpu_end - cpu_start;
    1a9f:	sub    rax,r13
  cpu_frequency = os_frequency * cpu_delta / os_delta;
    1aa2:	imul   rax,rax,0xf4240
    1aa9:	div    rcx
    printf("[PROFILE] Total duration: %lu (%fms @ CPU Frequency: %u)\n", total_delta, (f64)total_delta / (f64)freq * 1000.0, freq);
    1aac:	test   rbx,rbx
    1aaf:	js     1c64 <main+0xa04>
    1ab5:	pxor   xmm5,xmm5
    1ab9:	cvtsi2sd xmm5,rbx
    1abe:	movsd  QWORD PTR [rsp+0x8],xmm5
    1ac4:	movsd  xmm0,QWORD PTR [rsp+0x8]
    1aca:	pxor   xmm1,xmm1
    1ace:	mov    rdx,rax
    1ad1:	mov    rsi,rbx
    1ad4:	cvtsi2sd xmm1,rax
    1ad9:	lea    rdi,[rip+0x1b78]        # 3658 <_IO_stdin_used+0x658>
    1ae0:	mov    eax,0x1
    1ae5:	lea    rbx,[rip+0x3644]        # 5130 <g_profiler+0x10>
    1aec:	divsd  xmm0,xmm1
    1af0:	lea    rbp,[rbx+0x28000]
    1af7:	mulsd  xmm0,QWORD PTR [rip+0x1eb1]        # 39b0 <__PRETTY_FUNCTION__.9+0x60>
    1aff:	call   1070 <printf@plt>
    for (usize i = 0; i < STATIC_ARRAY_COUNT(g_profiler.zones); i++)
    1b04:	jmp    1b1d <main+0x8bd>
    1b06:	cs nop WORD PTR [rax+rax*1+0x0]
    1b10:	add    rbx,0x28
    1b14:	cmp    rbx,rbp
    1b17:	je     1a39 <main+0x7d9>
      if (zone->elapsed_inclusive)
    1b1d:	cmp    QWORD PTR [rbx+0x18],0x0
    1b22:	je     1b10 <main+0x8b0>
        f64 percent = ((f64)zone->elapsed_exclusive / (f64)total_delta) * 100.0;
    1b24:	mov    r8,QWORD PTR [rbx+0x10]
    1b28:	test   r8,r8
    1b2b:	js     1bd0 <main+0x970>
    1b31:	pxor   xmm0,xmm0
    1b35:	cvtsi2sd xmm0,r8
    1b3a:	divsd  xmm0,QWORD PTR [rsp+0x8]
        printf("[PROFILE] Zone '%.*s':\n"
    1b40:	mov    esi,DWORD PTR [rbx+0x8]
    1b43:	mov    rcx,QWORD PTR [rbx+0x20]
    1b47:	lea    rdi,[rip+0x1b4a]        # 3698 <_IO_stdin_used+0x698>
        f64 percent = ((f64)zone->elapsed_exclusive / (f64)total_delta) * 100.0;
    1b4e:	mulsd  xmm0,QWORD PTR [rip+0x1e62]        # 39b8 <__PRETTY_FUNCTION__.9+0x68>
        printf("[PROFILE] Zone '%.*s':\n"
    1b56:	mov    rdx,QWORD PTR [rbx]
    1b59:	mov    eax,0x1
    1b5e:	call   1070 <printf@plt>
        if (zone->elapsed_exclusive != zone->elapsed_inclusive)
    1b63:	mov    rsi,QWORD PTR [rbx+0x18]
    1b67:	cmp    QWORD PTR [rbx+0x10],rsi
    1b6b:	je     1b10 <main+0x8b0>
          f64 with_children_percent = ((f64)zone->elapsed_inclusive / (f64)total_delta) * 100.0;
    1b6d:	test   rsi,rsi
    1b70:	js     1bf8 <main+0x998>
    1b76:	pxor   xmm0,xmm0
    1b7a:	cvtsi2sd xmm0,rsi
    1b7f:	divsd  xmm0,QWORD PTR [rsp+0x8]
    1b85:	mulsd  xmm0,QWORD PTR [rip+0x1e2b]        # 39b8 <__PRETTY_FUNCTION__.9+0x68>
          printf("  Inclusive Timestamp Cycles: %lu (%.4f%%)\n", zone->elapsed_inclusive, with_children_percent);
    1b8d:	mov    eax,0x1
    1b92:	lea    rdi,[rip+0x1b57]        # 36f0 <_IO_stdin_used+0x6f0>
    1b99:	call   1070 <printf@plt>
    1b9e:	jmp    1b10 <main+0x8b0>
          LOG_INFO("Solutions (solution: %f, calculated: %f) match! :)", solution_sum, sum);
    1ba3:	mov    edx,0x64
    1ba8:	mov    edi,0x3
    1bad:	mov    eax,0x2
    1bb2:	lea    rcx,[rip+0x1a67]        # 3620 <_IO_stdin_used+0x620>
    1bb9:	lea    rsi,[rip+0x14ff]        # 30bf <_IO_stdin_used+0xbf>
    1bc0:	call   1ff0 <log_message>
    1bc5:	jmp    1984 <main+0x724>
    1bca:	nop    WORD PTR [rax+rax*1+0x0]
        f64 percent = ((f64)zone->elapsed_exclusive / (f64)total_delta) * 100.0;
    1bd0:	mov    rax,r8
    1bd3:	mov    rdx,r8
    1bd6:	pxor   xmm0,xmm0
    1bda:	shr    rax,1
    1bdd:	and    edx,0x1
    1be0:	or     rax,rdx
    1be3:	cvtsi2sd xmm0,rax
    1be8:	addsd  xmm0,xmm0
    1bec:	jmp    1b3a <main+0x8da>
    1bf1:	nop    DWORD PTR [rax+0x0]
          f64 with_children_percent = ((f64)zone->elapsed_inclusive / (f64)total_delta) * 100.0;
    1bf8:	mov    rax,rsi
    1bfb:	mov    rdx,rsi
    1bfe:	pxor   xmm0,xmm0
    1c02:	shr    rax,1
    1c05:	and    edx,0x1
    1c08:	or     rax,rdx
    1c0b:	cvtsi2sd xmm0,rax
    1c10:	addsd  xmm0,xmm0
    1c14:	jmp    1b7f <main+0x91f>
      LOG_ERROR("Solution dump is not large enough to hold actual solutions");
    1c19:	lea    rcx,[rip+0x1940]        # 3560 <_IO_stdin_used+0x560>
    1c20:	mov    edx,0x72
    1c25:	lea    rsi,[rip+0x1493]        # 30bf <_IO_stdin_used+0xbf>
    1c2c:	xor    eax,eax
    1c2e:	mov    edi,0x1
    1c33:	call   1ff0 <log_message>
    1c38:	jmp    1984 <main+0x724>
        LOG_ERROR("Solution pair counts (%d) and parsed pair count (%d) do not match", solution_pairs, pair_count);
    1c3d:	mov    r9d,ebx
    1c40:	mov    edx,0x6d
    1c45:	mov    edi,0x1
    1c4a:	xor    eax,eax
    1c4c:	lea    rcx,[rip+0x194d]        # 35a0 <_IO_stdin_used+0x5a0>
    1c53:	lea    rsi,[rip+0x1465]        # 30bf <_IO_stdin_used+0xbf>
    1c5a:	call   1ff0 <log_message>
    1c5f:	jmp    1984 <main+0x724>
    printf("[PROFILE] Total duration: %lu (%fms @ CPU Frequency: %u)\n", total_delta, (f64)total_delta / (f64)freq * 1000.0, freq);
    1c64:	mov    rdx,rbx
    1c67:	mov    rcx,rbx
    1c6a:	pxor   xmm0,xmm0
    1c6e:	shr    rdx,1
    1c71:	and    ecx,0x1
    1c74:	or     rdx,rcx
    1c77:	cvtsi2sd xmm0,rdx
    1c7c:	addsd  xmm0,xmm0
    1c80:	movsd  QWORD PTR [rsp+0x8],xmm0
    1c86:	jmp    1ac4 <main+0x864>
    .parent_index = g_profiler.current_parent_zone,
    1c8b:	mov    rcx,QWORD PTR [rip+0x3496]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    1c92:	mov    QWORD PTR [rip+0x348b],0x8        # 5128 <g_profiler+0x8>
    1c9d:	rdtsc
  return pass;
    1c9f:	lea    rdi,[rip+0x140f]        # 30b5 <_IO_stdin_used+0xb5>
    1ca6:	xor    ebx,ebx
    1ca8:	shl    rdx,0x20
    1cac:	mov    QWORD PTR [rsp+0x120],rdi
    1cb4:	or     rax,rdx
    1cb7:	mov    QWORD PTR [rsp+0x148],rcx
  f64 sum = 0.0;
    1cbf:	mov    QWORD PTR [rsp+0x8],0x0
    1cc8:	movq   xmm0,rax
    1ccd:	movhps xmm0,QWORD PTR [rip+0x35b4]        # 5288 <g_profiler+0x168>
    1cd4:	mov    QWORD PTR [rsp+0x128],0x3
    1ce0:	mov    QWORD PTR [rsp+0x140],0x8
    1cec:	movaps XMMWORD PTR [rsp+0x130],xmm0
    1cf4:	jmp    1873 <main+0x613>
  f64 c = 2.0 * asin(sqrt(a));
    1cf9:	call   1160 <sqrt@plt>
    1cfe:	jmp    1849 <main+0x5e9>
}
    1d03:	call   1060 <__stack_chk_fail@plt>
    1d08:	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001d10 <_start>:
    1d10:	endbr64
    1d14:	xor    ebp,ebp
    1d16:	mov    r9,rdx
    1d19:	pop    rsi
    1d1a:	mov    rdx,rsp
    1d1d:	and    rsp,0xfffffffffffffff0
    1d21:	push   rax
    1d22:	push   rsp
    1d23:	xor    r8d,r8d
    1d26:	xor    ecx,ecx
    1d28:	lea    rdi,[rip+0xfffffffffffff531]        # 1260 <main>
    1d2f:	call   QWORD PTR [rip+0x3283]        # 4fb8 <__libc_start_main@GLIBC_2.34>
    1d35:	hlt
    1d36:	cs nop WORD PTR [rax+rax*1+0x0]
    1d40:	lea    rdi,[rip+0x3399]        # 50e0 <stdout@GLIBC_2.2.5>
    1d47:	lea    rax,[rip+0x3392]        # 50e0 <stdout@GLIBC_2.2.5>
    1d4e:	cmp    rax,rdi
    1d51:	je     1d68 <_start+0x58>
    1d53:	mov    rax,QWORD PTR [rip+0x3266]        # 4fc0 <_ITM_deregisterTMCloneTable@Base>
    1d5a:	test   rax,rax
    1d5d:	je     1d68 <_start+0x58>
    1d5f:	jmp    rax
    1d61:	nop    DWORD PTR [rax+0x0]
    1d68:	ret
    1d69:	nop    DWORD PTR [rax+0x0]
    1d70:	lea    rdi,[rip+0x3369]        # 50e0 <stdout@GLIBC_2.2.5>
    1d77:	lea    rsi,[rip+0x3362]        # 50e0 <stdout@GLIBC_2.2.5>
    1d7e:	sub    rsi,rdi
    1d81:	mov    rax,rsi
    1d84:	shr    rsi,0x3f
    1d88:	sar    rax,0x3
    1d8c:	add    rsi,rax
    1d8f:	sar    rsi,1
    1d92:	je     1da8 <_start+0x98>
    1d94:	mov    rax,QWORD PTR [rip+0x3235]        # 4fd0 <_ITM_registerTMCloneTable@Base>
    1d9b:	test   rax,rax
    1d9e:	je     1da8 <_start+0x98>
    1da0:	jmp    rax
    1da2:	nop    WORD PTR [rax+rax*1+0x0]
    1da8:	ret
    1da9:	nop    DWORD PTR [rax+0x0]
    1db0:	endbr64
    1db4:	cmp    BYTE PTR [rip+0x334d],0x0        # 5108 <stderr@GLIBC_2.2.5+0x8>
    1dbb:	jne    1df0 <_start+0xe0>
    1dbd:	push   rbp
    1dbe:	cmp    QWORD PTR [rip+0x3212],0x0        # 4fd8 <__cxa_finalize@GLIBC_2.2.5>
    1dc6:	mov    rbp,rsp
    1dc9:	je     1dd8 <_start+0xc8>
    1dcb:	mov    rdi,QWORD PTR [rip+0x32d6]        # 50a8 <__dso_handle>
    1dd2:	call   QWORD PTR [rip+0x3200]        # 4fd8 <__cxa_finalize@GLIBC_2.2.5>
    1dd8:	call   1d40 <_start+0x30>
    1ddd:	mov    BYTE PTR [rip+0x3324],0x1        # 5108 <stderr@GLIBC_2.2.5+0x8>
    1de4:	pop    rbp
    1de5:	ret
    1de6:	cs nop WORD PTR [rax+rax*1+0x0]
    1df0:	ret
    1df1:	nop    DWORD PTR [rax+0x0]
    1df5:	data16 cs nop WORD PTR [rax+rax*1+0x0]
    1e00:	endbr64
    1e04:	jmp    1d70 <_start+0x60>
    1e09:	cs nop WORD PTR [rax+rax*1+0x0]
    1e13:	cs nop WORD PTR [rax+rax*1+0x0]
    1e1d:	cs nop WORD PTR [rax+rax*1+0x0]
    1e27:	cs nop WORD PTR [rax+rax*1+0x0]
    1e31:	cs nop WORD PTR [rax+rax*1+0x0]
    1e3b:	nop    DWORD PTR [rax+rax*1+0x0]

0000000000001e40 <__profile_end_pass>:
}

static
void __profile_end_pass(Profile_Pass pass)
{
    1e40:	mov    r8,QWORD PTR [rsp+0x30]
    1e45:	rdtsc
  // First!
  u64 elapsed = read_cpu_timer() - pass.start;

  // Pop parent
  g_profiler.current_parent_zone = pass.parent_index;
    1e47:	lea    rdi,[rip+0x32d2]        # 5120 <g_profiler>
  u64 elapsed = read_cpu_timer() - pass.start;
    1e4e:	mov    rcx,QWORD PTR [rsp+0x18]

  Profile_Zone *current = &g_profiler.zones[pass.zone_index];
  current->elapsed_exclusive += elapsed;
  current->hit_count += 1;
  current->name = pass.name; // Stupid...
    1e53:	movdqu xmm0,XMMWORD PTR [rsp+0x8]
    1e59:	shl    rdx,0x20
  g_profiler.current_parent_zone = pass.parent_index;
    1e5d:	mov    QWORD PTR [rip+0x32c4],r8        # 5128 <g_profiler+0x8>
    1e64:	or     rax,rdx
  Profile_Zone *current = &g_profiler.zones[pass.zone_index];
    1e67:	mov    rdx,QWORD PTR [rsp+0x28]
  u64 elapsed = read_cpu_timer() - pass.start;
    1e6c:	mov    rsi,rax
  current->elapsed_exclusive += elapsed;
    1e6f:	lea    rdx,[rdx+rdx*4]
  u64 elapsed = read_cpu_timer() - pass.start;
    1e73:	sub    rsi,rcx
  current->elapsed_inclusive = pass.old_elapsed_inclusive + elapsed; // So that only the final out of potential recursive calls writes inclusive time

  // Accumulate to parent time
  Profile_Zone *parent = &g_profiler.zones[pass.parent_index];
  parent->elapsed_exclusive -= elapsed;
    1e76:	sub    rcx,rax
  current->elapsed_exclusive += elapsed;
    1e79:	add    QWORD PTR [rdi+rdx*8+0x20],rsi
  current->elapsed_inclusive = pass.old_elapsed_inclusive + elapsed; // So that only the final out of potential recursive calls writes inclusive time
    1e7e:	add    rsi,QWORD PTR [rsp+0x20]
  current->hit_count += 1;
    1e83:	add    QWORD PTR [rdi+rdx*8+0x30],0x1
  current->elapsed_inclusive = pass.old_elapsed_inclusive + elapsed; // So that only the final out of potential recursive calls writes inclusive time
    1e89:	mov    QWORD PTR [rdi+rdx*8+0x28],rsi
  current->name = pass.name; // Stupid...
    1e8e:	movups XMMWORD PTR [rdi+rdx*8+0x10],xmm0
  parent->elapsed_exclusive -= elapsed;
    1e93:	lea    rdx,[r8+r8*4]
    1e97:	add    QWORD PTR [rdi+rdx*8+0x20],rcx
}
    1e9c:	ret
    1e9d:	nop    DWORD PTR [rax]

0000000000001ea0 <lookup_json_object>:
{
    1ea0:	push   r12
    1ea2:	push   rbp
    1ea3:	mov    rbp,rdx
    1ea6:	push   rbx
    1ea7:	sub    rsp,0x30
    .parent_index = g_profiler.current_parent_zone,
    1eab:	mov    rcx,QWORD PTR [rip+0x3276]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    1eb2:	mov    QWORD PTR [rip+0x326b],0x4        # 5128 <g_profiler+0x8>
    1ebd:	rdtsc
    for (JSON_Object *cursor = current->first_child; cursor; cursor = cursor->next_sibling)
    1ebf:	mov    rbx,QWORD PTR [rdi+0x20]
    1ec3:	shl    rdx,0x20
  return pass;
    1ec7:	mov    QWORD PTR [rsp+0x28],rcx
    1ecc:	mov    QWORD PTR [rsp+0x8],0x12
    1ed5:	or     rax,rdx
    1ed8:	lea    rdx,[rip+0x19b1]        # 3890 <__func__.1>
    1edf:	movq   xmm0,rax
    1ee4:	mov    QWORD PTR [rsp],rdx
    1ee8:	movhps xmm0,QWORD PTR [rip+0x32f9]        # 51e8 <g_profiler+0xc8>
    1eef:	mov    QWORD PTR [rsp+0x20],0x4
    1ef8:	movaps XMMWORD PTR [rsp+0x10],xmm0
    1efd:	test   rbx,rbx
    1f00:	je     1f31 <lookup_json_object+0x91>
    1f02:	mov    r12,rsi
    1f05:	jmp    1f19 <lookup_json_object+0x79>
    1f07:	nop    WORD PTR [rax+rax*1+0x0]
    1f10:	mov    rbx,QWORD PTR [rbx+0x28]
    1f14:	test   rbx,rbx
    1f17:	je     1f31 <lookup_json_object+0x91>
  return a.count == b.count && memcmp(a.data, b.data, a.count) == 0;
    1f19:	cmp    rbp,QWORD PTR [rbx+0x8]
    1f1d:	jne    1f10 <lookup_json_object+0x70>
    1f1f:	mov    rsi,QWORD PTR [rbx]
    1f22:	mov    rdx,rbp
    1f25:	mov    rdi,r12
    1f28:	call   10d0 <memcmp@plt>
    1f2d:	test   eax,eax
    1f2f:	jne    1f10 <lookup_json_object+0x70>
  profile_end_func();
    1f31:	sub    rsp,0x30
    1f35:	movdqa xmm0,XMMWORD PTR [rsp+0x30]
    1f3b:	movups XMMWORD PTR [rsp],xmm0
    1f3f:	movdqa xmm0,XMMWORD PTR [rsp+0x40]
    1f45:	movups XMMWORD PTR [rsp+0x10],xmm0
    1f4a:	movdqa xmm0,XMMWORD PTR [rsp+0x50]
    1f50:	movups XMMWORD PTR [rsp+0x20],xmm0
    1f55:	call   1e40 <__profile_end_pass>
}
    1f5a:	add    rsp,0x60
    1f5e:	mov    rax,rbx
    1f61:	pop    rbx
    1f62:	pop    rbp
    1f63:	pop    r12
    1f65:	ret
    1f66:	cs nop WORD PTR [rax+rax*1+0x0]

0000000000001f70 <file_size>:
{
    1f70:	sub    rsp,0xa8
  stat(name, &stats);
    1f77:	mov    rsi,QWORD PTR fs:0x28
    1f80:	mov    QWORD PTR [rsp+0x98],rsi
    1f88:	mov    rsi,rsp
    1f8b:	call   1100 <stat@plt>
  return stats.st_size;
    1f90:	mov    rax,QWORD PTR [rsp+0x30]
}
    1f95:	mov    rdx,QWORD PTR [rsp+0x98]
    1f9d:	sub    rdx,QWORD PTR fs:0x28
    1fa6:	jne    1fb0 <file_size+0x40>
    1fa8:	add    rsp,0xa8
    1faf:	ret
    1fb0:	call   1060 <__stack_chk_fail@plt>
    1fb5:	data16 cs nop WORD PTR [rax+rax*1+0x0]

0000000000001fc0 <strings_equal>:
  return a.count == b.count && memcmp(a.data, b.data, a.count) == 0;
    1fc0:	cmp    rsi,rcx
    1fc3:	je     1fd0 <strings_equal+0x10>
    1fc5:	xor    eax,eax
}
    1fc7:	ret
    1fc8:	nop    DWORD PTR [rax+rax*1+0x0]
    1fd0:	mov    rax,rdx
{
    1fd3:	sub    rsp,0x8
    1fd7:	mov    rdx,rsi
  return a.count == b.count && memcmp(a.data, b.data, a.count) == 0;
    1fda:	mov    rsi,rax
    1fdd:	call   10d0 <memcmp@plt>
    1fe2:	test   eax,eax
    1fe4:	sete   al
}
    1fe7:	add    rsp,0x8
    1feb:	ret
    1fec:	nop    DWORD PTR [rax+0x0]

0000000000001ff0 <log_message>:
{
    1ff0:	push   rbp
    1ff1:	mov    r10,rdx
    1ff4:	mov    rbp,rcx
    1ff7:	push   rbx
    1ff8:	sub    rsp,0xd8
    1fff:	mov    QWORD PTR [rsp+0x40],r8
    2004:	mov    QWORD PTR [rsp+0x48],r9
    2009:	test   al,al
    200b:	je     2044 <log_message+0x54>
    200d:	movaps XMMWORD PTR [rsp+0x50],xmm0
    2012:	movaps XMMWORD PTR [rsp+0x60],xmm1
    2017:	movaps XMMWORD PTR [rsp+0x70],xmm2
    201c:	movaps XMMWORD PTR [rsp+0x80],xmm3
    2024:	movaps XMMWORD PTR [rsp+0x90],xmm4
    202c:	movaps XMMWORD PTR [rsp+0xa0],xmm5
    2034:	movaps XMMWORD PTR [rsp+0xb0],xmm6
    203c:	movaps XMMWORD PTR [rsp+0xc0],xmm7
  FILE *stream = stderr;
    2044:	mov    rbx,QWORD PTR fs:0x28
    204d:	mov    QWORD PTR [rsp+0x18],rbx
    2052:	mov    rbx,QWORD PTR [rip+0x30a7]        # 5100 <stderr@GLIBC_2.2.5>
    fprintf(stream, "[" LOG_TITLE " %s]: (%s:%lu) ", level_strings[level], file, line);
    2059:	mov    eax,edi
    205b:	lea    rcx,[rip+0x305e]        # 50c0 <level_strings>
    2062:	mov    rdx,QWORD PTR [rcx+rax*8]
  if (level <= LOG_ERROR)
    2066:	cmp    edi,0x1
    2069:	jbe    20e8 <log_message+0xf8>
      stream = stdout;
    206b:	cmp    edi,0x3
    206e:	cmove  rbx,QWORD PTR [rip+0x306a]        # 50e0 <stdout@GLIBC_2.2.5>
    fprintf(stream, "[" LOG_TITLE " %s]: ", level_strings[level]);
    2076:	xor    eax,eax
    2078:	lea    rsi,[rip+0xfba]        # 3039 <_IO_stdin_used+0x39>
    207f:	mov    rdi,rbx
    2082:	call   10f0 <fprintf@plt>
  vfprintf(stream, message, args);
    2087:	mov    rsi,rbp
    208a:	mov    rdi,rbx
    208d:	mov    rdx,rsp
  va_start(args, message);
    2090:	mov    DWORD PTR [rsp],0x20
    2097:	lea    rax,[rsp+0xf0]
    209f:	mov    DWORD PTR [rsp+0x4],0x30
    20a7:	mov    QWORD PTR [rsp+0x8],rax
    20ac:	lea    rax,[rsp+0x20]
    20b1:	mov    QWORD PTR [rsp+0x10],rax
  vfprintf(stream, message, args);
    20b6:	call   1120 <vfprintf@plt>
  fprintf(stream, "\n");
    20bb:	mov    rsi,rbx
    20be:	mov    edi,0xa
    20c3:	call   10c0 <fputc@plt>
}
    20c8:	mov    rax,QWORD PTR [rsp+0x18]
    20cd:	sub    rax,QWORD PTR fs:0x28
    20d6:	jne    2101 <log_message+0x111>
    20d8:	add    rsp,0xd8
    20df:	pop    rbx
    20e0:	pop    rbp
    20e1:	ret
    20e2:	nop    WORD PTR [rax+rax*1+0x0]
    fprintf(stream, "[" LOG_TITLE " %s]: (%s:%lu) ", level_strings[level], file, line);
    20e8:	mov    rcx,rsi
    20eb:	mov    r8,r10
    20ee:	lea    rsi,[rip+0xf2d]        # 3022 <_IO_stdin_used+0x22>
    20f5:	mov    rdi,rbx
    20f8:	xor    eax,eax
    20fa:	call   10f0 <fprintf@plt>
    20ff:	jmp    2087 <log_message+0x97>
}
    2101:	call   1060 <__stack_chk_fail@plt>
    2106:	cs nop WORD PTR [rax+rax*1+0x0]

0000000000002110 <read_file_to_memory>:
{
    2110:	push   r12
    2112:	mov    r12,rsi
  FILE *file = fopen(name, "rb");
    2115:	lea    rsi,[rip+0xf2b]        # 3047 <_IO_stdin_used+0x47>
{
    211c:	push   rbp
    211d:	push   rbx
    211e:	mov    rbx,rdi
    2121:	sub    rsp,0x10
    2125:	mov    QWORD PTR [rsp+0x8],rdx
  FILE *file = fopen(name, "rb");
    212a:	call   1110 <fopen@plt>
  if (file == NULL)
    212f:	mov    rdx,QWORD PTR [rsp+0x8]
    2134:	test   rax,rax
    2137:	je     2163 <read_file_to_memory+0x53>
    2139:	mov    rbp,rax
  usize byte_count = fread(buffer, sizeof(u8), buffer_size, file);
    213c:	mov    rdi,r12
    213f:	mov    rcx,rax
    2142:	mov    esi,0x1
    2147:	call   1040 <fread@plt>
  fclose(file);
    214c:	mov    rdi,rbp
  usize byte_count = fread(buffer, sizeof(u8), buffer_size, file);
    214f:	mov    rbx,rax
  fclose(file);
    2152:	call   1050 <fclose@plt>
}
    2157:	add    rsp,0x10
    215b:	mov    rax,rbx
    215e:	pop    rbx
    215f:	pop    rbp
    2160:	pop    r12
    2162:	ret
    LOG_ERROR("Unable to open file: %s", name);
    2163:	mov    r8,rbx
    2166:	lea    rcx,[rip+0xedd]        # 304a <_IO_stdin_used+0x4a>
    216d:	xor    eax,eax
    216f:	xor    ebx,ebx
    2171:	mov    edx,0x17b
    2176:	lea    rsi,[rip+0xe98]        # 3015 <_IO_stdin_used+0x15>
    217d:	mov    edi,0x1
    2182:	call   1ff0 <log_message>
    return 0;
    2187:	jmp    2157 <read_file_to_memory+0x47>
    2189:	nop    DWORD PTR [rax+0x0]

0000000000002190 <arena_make>:
{
    2190:	push   rbp
    2191:	mov    rbp,rdi
    2194:	push   rbx
    2195:	mov    rbx,rsi
  arena.base = (u8 *)calloc(reserve_size, 1);
    2198:	mov    esi,0x1
    219d:	mov    rdi,rbx
{
    21a0:	sub    rsp,0x8
  arena.base = (u8 *)calloc(reserve_size, 1);
    21a4:	call   10e0 <calloc@plt>
  if (arena.base == NULL)
    21a9:	test   rax,rax
    21ac:	je     21cc <arena_make+0x3c>
  return arena;
    21ae:	movq   xmm0,rbx
    21b3:	mov    QWORD PTR [rbp+0x0],rax
}
    21b7:	mov    rax,rbp
  return arena;
    21ba:	mov    DWORD PTR [rbp+0x18],0x0
    21c1:	movups XMMWORD PTR [rbp+0x8],xmm0
}
    21c5:	add    rsp,0x8
    21c9:	pop    rbx
    21ca:	pop    rbp
    21cb:	ret
    LOG_FATAL("Failed to allocate arena memory", EXT_ARENA_ALLOCATION);
    21cc:	xor    edi,edi
    21ce:	lea    rcx,[rip+0x10eb]        # 32c0 <_IO_stdin_used+0x2c0>
    21d5:	mov    edx,0x1d9
    21da:	lea    rsi,[rip+0xe34]        # 3015 <_IO_stdin_used+0x15>
    21e1:	call   1ff0 <log_message>
    21e6:	mov    edi,0xffffffff
    21eb:	call   1150 <exit@plt>

00000000000021f0 <arena_make_backed>:
{
    21f0:	sub    rsp,0x8
  ASSERT(backing_buffer != NULL, "Backing buffer for arena must not be NULL!");
    21f4:	test   rsi,rsi
    21f7:	je     11c0 <arena_make_backed.cold>
  ASSERT(backing_size   != 0,    "Backing buffer size for arena must not be 0!");
    21fd:	test   rdx,rdx
    2200:	je     11df <arena_make_backed.cold+0x1f>
    2206:	movq   xmm0,rdx
  return arena;
    220b:	mov    QWORD PTR [rdi],rsi
    220e:	mov    rax,rdi
    2211:	mov    DWORD PTR [rdi+0x18],0x1
    2218:	movups XMMWORD PTR [rdi+0x8],xmm0
}
    221c:	add    rsp,0x8
    2220:	ret
    2221:	nop    DWORD PTR [rax+0x0]
    2225:	data16 cs nop WORD PTR [rax+rax*1+0x0]

0000000000002230 <arena_free>:
{
    2230:	mov    rax,rdi
  if (!(arena->flags & ARENA_FLAG_BUFFER_BACKED))
    2233:	test   BYTE PTR [rdi+0x18],0x1
    2237:	je     2248 <arena_free+0x18>
  ZERO_STRUCT(arena);
    2239:	pxor   xmm0,xmm0
    223d:	movups XMMWORD PTR [rdi],xmm0
    2240:	movups XMMWORD PTR [rdi+0x10],xmm0
    2244:	ret
    2245:	nop    DWORD PTR [rax]
{
    2248:	sub    rsp,0x18
    free(arena->base);
    224c:	mov    rdi,QWORD PTR [rdi]
    224f:	mov    QWORD PTR [rsp+0x8],rax
    2254:	call   1030 <free@plt>
    2259:	mov    rax,QWORD PTR [rsp+0x8]
  ZERO_STRUCT(arena);
    225e:	pxor   xmm0,xmm0
    2262:	movups XMMWORD PTR [rax],xmm0
    2265:	movups XMMWORD PTR [rax+0x10],xmm0
}
    2269:	add    rsp,0x18
    226d:	ret
    226e:	xchg   ax,ax

0000000000002270 <arena_alloc>:
void *arena_alloc(Arena *arena, isize size, isize alignment) {
    2270:	push   rbp
    2271:	push   rbx
    2272:	sub    rsp,0x8
  ASSERT(arena->base != NULL, "Arena memory is null");
    2276:	mov    rax,QWORD PTR [rdi]
    2279:	test   rax,rax
    227c:	je     11fe <arena_alloc.cold>
    2282:	mov    rcx,rdx
  isize aligned_offset = ALIGN_ROUND_UP(arena->next_offset, alignment);
    2285:	mov    rdx,QWORD PTR [rdi+0x10]
  if ((aligned_offset + size) > arena->capacity)
    2289:	mov    r9,QWORD PTR [rdi+0x8]
    228d:	mov    rbx,rdi
  isize aligned_offset = ALIGN_ROUND_UP(arena->next_offset, alignment);
    2290:	lea    rdx,[rdx+rcx*1-0x1]
    2295:	neg    rcx
    2298:	and    rdx,rcx
  if ((aligned_offset + size) > arena->capacity)
    229b:	lea    rbp,[rdx+rsi*1]
    229f:	cmp    rbp,r9
    22a2:	jg     22bd <arena_alloc+0x4d>
  ZERO_SIZE(ptr, size); // make sure memory is zeroed out
    22a4:	lea    rdi,[rax+rdx*1]
    22a8:	mov    rdx,rsi
    22ab:	xor    esi,esi
    22ad:	call   10a0 <memset@plt>
  arena->next_offset = aligned_offset + size;
    22b2:	mov    QWORD PTR [rbx+0x10],rbp
}
    22b6:	add    rsp,0x8
    22ba:	pop    rbx
    22bb:	pop    rbp
    22bc:	ret
    LOG_FATAL("Not enough memory in arena, NEED: %ld bytes HAVE: %ld bytes",
    22bd:	xor    edi,edi
    22bf:	mov    r8,rbp
    22c2:	lea    rcx,[rip+0x10e7]        # 33b0 <_IO_stdin_used+0x3b0>
    22c9:	xor    eax,eax
    22cb:	mov    edx,0x207
    22d0:	lea    rsi,[rip+0xd3e]        # 3015 <_IO_stdin_used+0x15>
    22d7:	call   1ff0 <log_message>
    22dc:	mov    edi,0xffffffff
    22e1:	call   1150 <exit@plt>
    22e6:	cs nop WORD PTR [rax+rax*1+0x0]

00000000000022f0 <read_file_to_arena>:
{
    22f0:	push   r15
    22f2:	push   r14
    22f4:	push   r13
    22f6:	push   r12
    22f8:	push   rbp
    22f9:	mov    rbp,rdi
    22fc:	push   rbx
    22fd:	sub    rsp,0xb8
    2304:	mov    r12,QWORD PTR fs:0x28
    230d:	mov    QWORD PTR [rsp+0xa8],r12
    2315:	mov    r12,rsi
  stat(name, &stats);
    2318:	lea    rsi,[rsp+0x10]
    231d:	mov    rdi,r12
    2320:	call   1100 <stat@plt>
  u8 *buffer = arena_calloc(arena, buffer_size, u8);
    2325:	mov    rdi,rbp
  Arena save = *arena;
    2328:	mov    r15,QWORD PTR [rbp+0x0]
    232c:	mov    r14d,DWORD PTR [rbp+0x18]
  return stats.st_size;
    2330:	mov    rbx,QWORD PTR [rsp+0x40]
  Arena save = *arena;
    2335:	movdqu xmm0,XMMWORD PTR [rbp+0x8]
  u8 *buffer = arena_calloc(arena, buffer_size, u8);
    233a:	mov    edx,0x1
    233f:	mov    rsi,rbx
  Arena save = *arena;
    2342:	movaps XMMWORD PTR [rsp],xmm0
  u8 *buffer = arena_calloc(arena, buffer_size, u8);
    2346:	call   2270 <arena_alloc>
  if (read_file_to_memory(name, buffer, buffer_size) != buffer_size)
    234b:	mov    rdx,rbx
    234e:	mov    rdi,r12
    2351:	mov    rsi,rax
  u8 *buffer = arena_calloc(arena, buffer_size, u8);
    2354:	mov    r13,rax
  if (read_file_to_memory(name, buffer, buffer_size) != buffer_size)
    2357:	call   2110 <read_file_to_memory>
    235c:	cmp    rax,rbx
    235f:	je     2394 <read_file_to_arena+0xa4>
    LOG_ERROR("Unable to read file: %s", name);
    2361:	mov    r8,r12
    2364:	mov    edx,0x19d
    2369:	mov    edi,0x1
    236e:	xor    eax,eax
    2370:	lea    rcx,[rip+0xceb]        # 3062 <_IO_stdin_used+0x62>
    2377:	lea    rsi,[rip+0xc97]        # 3015 <_IO_stdin_used+0x15>
    237e:	call   1ff0 <log_message>
    *arena = save; // Rollback allocation
    2383:	movdqa xmm0,XMMWORD PTR [rsp]
    2388:	mov    QWORD PTR [rbp+0x0],r15
    238c:	mov    DWORD PTR [rbp+0x18],r14d
    2390:	movups XMMWORD PTR [rbp+0x8],xmm0
  return result;
    2394:	mov    rax,r13
    2397:	mov    rdx,rbx
}
    239a:	mov    rcx,QWORD PTR [rsp+0xa8]
    23a2:	sub    rcx,QWORD PTR fs:0x28
    23ab:	jne    23bf <read_file_to_arena+0xcf>
    23ad:	add    rsp,0xb8
    23b4:	pop    rbx
    23b5:	pop    rbp
    23b6:	pop    r12
    23b8:	pop    r13
    23ba:	pop    r14
    23bc:	pop    r15
    23be:	ret
    23bf:	call   1060 <__stack_chk_fail@plt>
    23c4:	nop
    23c5:	data16 cs nop WORD PTR [rax+rax*1+0x0]

00000000000023d0 <arena_pop_to>:
  ASSERT(offset < arena->next_offset,
    23d0:	cmp    QWORD PTR [rdi+0x10],rsi
    23d4:	jle    121d <arena_pop_to.cold>
  arena->next_offset = offset;
    23da:	mov    QWORD PTR [rdi+0x10],rsi
    23de:	ret
    23df:	nop

00000000000023e0 <arena_pop>:
  arena_pop_to(arena, arena->next_offset - size);
    23e0:	mov    rdx,QWORD PTR [rdi+0x10]
    23e4:	mov    rax,rdx
    23e7:	sub    rax,rsi
  ASSERT(offset < arena->next_offset,
    23ea:	cmp    rdx,rax
    23ed:	jle    1223 <arena_pop.cold>
  arena->next_offset = offset;
    23f3:	mov    QWORD PTR [rdi+0x10],rax
    23f7:	ret
    23f8:	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002400 <arena_clear>:
  arena->next_offset = 0;
    2400:	mov    QWORD PTR [rdi+0x10],0x0
}
    2408:	ret
    2409:	nop    DWORD PTR [rax+0x0]

0000000000002410 <scratch_begin>:
  return scratch;
    2410:	mov    rdx,QWORD PTR [rdi+0x10]
    2414:	mov    rax,rdi
}
    2417:	ret
    2418:	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002420 <scratch_end>:
  arena_pop_to(scratch->arena, scratch->offset_save);
    2420:	mov    rax,QWORD PTR [rdi]
    2423:	mov    rdx,QWORD PTR [rdi+0x8]
  ASSERT(offset < arena->next_offset,
    2427:	cmp    rdx,QWORD PTR [rax+0x10]
    242b:	jge    1229 <scratch_end.cold>
  ZERO_STRUCT(scratch);
    2431:	pxor   xmm0,xmm0
  arena->next_offset = offset;
    2435:	mov    QWORD PTR [rax+0x10],rdx
  ZERO_STRUCT(scratch);
    2439:	movups XMMWORD PTR [rdi],xmm0
    243c:	ret
    243d:	nop    DWORD PTR [rax]

0000000000002440 <get_json_token>:
  return parser->at < parser->source.count;
    2440:	mov    r8,QWORD PTR [rsi+0x10]
    2444:	mov    rdx,QWORD PTR [rsi+0x8]
{
    2448:	mov    r9,rdi
  while (parser_incomplete(parser)  &&
    244b:	cmp    r8,rdx
    244e:	jae    24cb <get_json_token+0x8b>
  return parser->source.data + parser->at;
    2450:	mov    rcx,QWORD PTR [rsi]
    2453:	mov    edi,0x800013
    2458:	nop    DWORD PTR [rax+rax*1+0x0]
    2460:	movzx  eax,BYTE PTR [rcx+r8*1]
    2465:	sub    eax,0x9
    2468:	cmp    al,0x17
    246a:	ja     24a0 <get_json_token+0x60>
    246c:	bt     rdi,rax
    2470:	jae    24a0 <get_json_token+0x60>
  parser->at += advance;
    2472:	add    r8,0x1
    2476:	mov    QWORD PTR [rsi+0x10],r8
  while (parser_incomplete(parser)  &&
    247a:	cmp    r8,rdx
    247d:	jne    2460 <get_json_token+0x20>
  parser->at += advance;
    247f:	add    rdx,0x1
  JSON_Token token = {0};
    2483:	xor    eax,eax
    2485:	xor    r10d,r10d
  parser->at += advance;
    2488:	mov    QWORD PTR [rsi+0x10],rdx
  JSON_Token token = {0};
    248c:	xor    edx,edx
  return token;
    248e:	mov    QWORD PTR [r9+0x10],rax
}
    2492:	mov    rax,r9
  return token;
    2495:	mov    DWORD PTR [r9],edx
    2498:	mov    QWORD PTR [r9+0x8],r10
}
    249c:	ret
    249d:	nop    DWORD PTR [rax]
  if (parser_incomplete(parser)) // If we've not reached the end of file
    24a0:	cmp    r8,rdx
    24a3:	jae    24cb <get_json_token+0x8b>
  return parser->source.data + parser->at;
    24a5:	lea    r10,[rcx+r8*1]
    switch (*parser_at(parser))
    24a9:	movzx  eax,BYTE PTR [r10]
    24ad:	sub    eax,0x22
    24b0:	cmp    al,0x5b
    24b2:	ja     2528 <get_json_token+0xe8>
    24b4:	lea    rdi,[rip+0x1265]        # 3720 <_IO_stdin_used+0x720>
    24bb:	movzx  eax,al
{
    24be:	sub    rsp,0x18
    switch (*parser_at(parser))
    24c2:	movsxd rax,DWORD PTR [rdi+rax*4]
    24c6:	add    rax,rdi
    24c9:	jmp    rax
    24cb:	mov    rdx,r8
    24ce:	jmp    247f <get_json_token+0x3f>
  return memcmp(parser_at(parser), literal_string.data, literal_string.count) == 0;
    24d0:	cmp    DWORD PTR [r10],0x736c6166
    24d7:	je     26c0 <get_json_token+0x280>
    24dd:	mov    QWORD PTR [rsp],r10
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
    24e1:	lea    rcx,[rip+0xf08]        # 33f0 <_IO_stdin_used+0x3f0>
    24e8:	mov    edx,0xee
    24ed:	mov    QWORD PTR [rsp+0x8],r9
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
    24f2:	lea    rsi,[rip+0xb0b]        # 3004 <_IO_stdin_used+0x4>
    24f9:	mov    edi,0x1
    24fe:	xor    eax,eax
    2500:	call   1ff0 <log_message>
    2505:	mov    r10,QWORD PTR [rsp]
    2509:	mov    r9,QWORD PTR [rsp+0x8]
  JSON_Token token = {0};
    250e:	xor    eax,eax
    2510:	xor    edx,edx
  return token;
    2512:	mov    QWORD PTR [r9+0x10],rax
}
    2516:	mov    rax,r9
  return token;
    2519:	mov    DWORD PTR [r9],edx
    251c:	mov    QWORD PTR [r9+0x8],r10
}
    2520:	add    rsp,0x18
    2524:	ret
    2525:	nop    DWORD PTR [rax]
  JSON_Token token = {0};
    2528:	xor    eax,eax
    252a:	xor    edx,edx
    252c:	jmp    248e <get_json_token+0x4e>
  ASSERT(parser->at < parser->source.count, "Attempted to read past parser source");
    2531:	mov    rdi,QWORD PTR [rsi+0x10]
    2535:	cmp    rdi,rdx
    2538:	jae    122f <get_json_token.cold>
    253e:	sub    rdx,rdi
        usize digit_count = 0;
    2541:	xor    eax,eax
    2543:	lea    r8,[rcx+rdi*1]
        while (is_numeric(*parser_at(parser)))
    2547:	movzx  ecx,BYTE PTR [r8+rax*1]
  switch (ch)
    254c:	cmp    cl,0x2e
    254f:	ja     2697 <get_json_token+0x257>
    2555:	cmp    cl,0x2c
    2558:	ja     26a3 <get_json_token+0x263>
        token.type  = JSON_TOKEN_NUMBER;
    255e:	mov    edx,0x8
      break;
    2563:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    2565:	add    r8,0x1
        token.value.count = 1;
    2569:	mov    eax,0x1
        token.type = JSON_TOKEN_COMMA;
    256e:	mov    edx,0x5
  parser->at += advance;
    2573:	mov    QWORD PTR [rsi+0x10],r8
}
    2577:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    2579:	add    r8,0x1
        token.value.count = 1;
    257d:	mov    eax,0x1
        token.type = JSON_TOKEN_COLON;
    2582:	mov    edx,0x6
  parser->at += advance;
    2587:	mov    QWORD PTR [rsi+0x10],r8
}
    258b:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    258d:	add    r8,0x1
        token.value.count = 1;
    2591:	mov    eax,0x1
        token.type = JSON_TOKEN_OPEN_SQUARE_BRACE;
    2596:	mov    edx,0x3
  parser->at += advance;
    259b:	mov    QWORD PTR [rsi+0x10],r8
}
    259f:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    25a4:	add    r8,0x1
        token.value.count = 1;
    25a8:	mov    eax,0x1
        token.type = JSON_TOKEN_CLOSE_SQUARE_BRACE;
    25ad:	mov    edx,0x4
  parser->at += advance;
    25b2:	mov    QWORD PTR [rsi+0x10],r8
}
    25b6:	jmp    2512 <get_json_token+0xd2>
        if (parser_token_is_literal(parser, string))
    25bb:	cmp    DWORD PTR [r10],0x6c6c756e
    25c2:	jne    26df <get_json_token+0x29f>
  parser->at += advance;
    25c8:	add    r8,0x4
  JSON_Token token = {0};
    25cc:	xor    eax,eax
          token.type  = JSON_TOKEN_NULL;
    25ce:	mov    edx,0xb
  parser->at += advance;
    25d3:	mov    QWORD PTR [rsi+0x10],r8
}
    25d7:	jmp    2512 <get_json_token+0xd2>
        if (parser_token_is_literal(parser, string))
    25dc:	cmp    DWORD PTR [r10],0x65757274
    25e3:	jne    26f9 <get_json_token+0x2b9>
  parser->at += advance;
    25e9:	add    r8,0x4
  JSON_Token token = {0};
    25ed:	xor    eax,eax
          token.type  = JSON_TOKEN_TRUE;
    25ef:	mov    edx,0x9
  parser->at += advance;
    25f4:	mov    QWORD PTR [rsi+0x10],r8
}
    25f8:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    25fd:	add    r8,0x1
        token.value.count = 1;
    2601:	mov    eax,0x1
        token.type = JSON_TOKEN_CLOSE_CURLY_BRACE;
    2606:	mov    edx,0x2
  parser->at += advance;
    260b:	mov    QWORD PTR [rsi+0x10],r8
}
    260f:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    2614:	add    r8,0x1
        token.value.count = 1;
    2618:	mov    eax,0x1
        token.type = JSON_TOKEN_OPEN_CURLY_BRACE;
    261d:	mov    edx,0x1
  parser->at += advance;
    2622:	mov    QWORD PTR [rsi+0x10],r8
}
    2626:	jmp    2512 <get_json_token+0xd2>
  parser->at += advance;
    262b:	lea    r10,[r8+0x1]
    262f:	mov    QWORD PTR [rsi+0x10],r10
  ASSERT(parser->at < parser->source.count, "Attempted to read past parser source");
    2633:	cmp    r10,rdx
    2636:	jae    122f <get_json_token.cold>
    263c:	mov    rdi,r10
    263f:	jmp    266d <get_json_token+0x22d>
    2641:	nop    WORD PTR [rax+rax*1+0x0]
    264a:	data16 cs nop WORD PTR [rax+rax*1+0x0]
    2655:	data16 cs nop WORD PTR [rax+rax*1+0x0]
  parser->at += advance;
    2660:	mov    QWORD PTR [rsi+0x10],rdi
  ASSERT(parser->at < parser->source.count, "Attempted to read past parser source");
    2664:	cmp    rdi,rdx
    2667:	jae    2713 <get_json_token+0x2d3>
        while (*parser_at(parser) != '"')
    266d:	movzx  r11d,BYTE PTR [rcx+rdi*1]
    2672:	mov    rax,rdi
  parser->at += advance;
    2675:	add    rdi,0x1
        while (*parser_at(parser) != '"')
    2679:	cmp    r11b,0x22
    267d:	jne    2660 <get_json_token+0x220>
        token.value.count = string_count;
    267f:	sub    rax,r8
  parser->at += advance;
    2682:	mov    QWORD PTR [rsi+0x10],rdi
  return parser->source.data + parser->at;
    2686:	add    r10,rcx
        token.type = JSON_TOKEN_STRING;
    2689:	mov    edx,0x7
        token.value.count = string_count;
    268e:	sub    rax,0x1
}
    2692:	jmp    2512 <get_json_token+0xd2>
  switch (ch)
    2697:	sub    ecx,0x30
    269a:	cmp    cl,0x9
    269d:	ja     255e <get_json_token+0x11e>
          digit_count += 1;
    26a3:	add    rax,0x1
  parser->at += advance;
    26a7:	lea    rcx,[rdi+rax*1]
    26ab:	mov    QWORD PTR [rsi+0x10],rcx
  ASSERT(parser->at < parser->source.count, "Attempted to read past parser source");
    26af:	cmp    rdx,rax
    26b2:	jne    2547 <get_json_token+0x107>
    26b8:	jmp    122f <get_json_token.cold>
    26bd:	nop    DWORD PTR [rax]
  return memcmp(parser_at(parser), literal_string.data, literal_string.count) == 0;
    26c0:	cmp    BYTE PTR [r10+0x4],0x65
    26c5:	jne    24dd <get_json_token+0x9d>
  parser->at += advance;
    26cb:	add    r8,0x5
  JSON_Token token = {0};
    26cf:	xor    eax,eax
          token.type  = JSON_TOKEN_FALSE;
    26d1:	mov    edx,0xa
  parser->at += advance;
    26d6:	mov    QWORD PTR [rsi+0x10],r8
}
    26da:	jmp    2512 <get_json_token+0xd2>
    26df:	mov    QWORD PTR [rsp],r10
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
    26e3:	lea    rcx,[rip+0xd06]        # 33f0 <_IO_stdin_used+0x3f0>
    26ea:	mov    edx,0xfd
    26ef:	mov    QWORD PTR [rsp+0x8],r9
    26f4:	jmp    24f2 <get_json_token+0xb2>
    26f9:	mov    QWORD PTR [rsp],r10
          LOG_ERROR("Encountered unrecognized literal at byte %lu", parser->at);
    26fd:	lea    rcx,[rip+0xcec]        # 33f0 <_IO_stdin_used+0x3f0>
    2704:	mov    edx,0xdf
    2709:	mov    QWORD PTR [rsp+0x8],r9
    270e:	jmp    24f2 <get_json_token+0xb2>
    2713:	jmp    122f <get_json_token.cold>
    2718:	nop    DWORD PTR [rax+rax*1+0x0]

0000000000002720 <parse_json_children>:
{
    2720:	push   r15
    2722:	push   r14
    2724:	push   r13
    2726:	push   r12
    2728:	push   rbp
    2729:	push   rbx
    272a:	sub    rsp,0xc8
    .parent_index = g_profiler.current_parent_zone,
    2731:	mov    r8,QWORD PTR [rip+0x29f0]        # 5128 <g_profiler+0x8>
    2738:	mov    QWORD PTR [rsp+0x10],rdi
    273d:	mov    r13,QWORD PTR fs:0x28
    2746:	mov    QWORD PTR [rsp+0xb8],r13
    274e:	mov    r13d,edx
  g_profiler.current_parent_zone = zone_index;
    2751:	mov    QWORD PTR [rip+0x29cc],0x2        # 5128 <g_profiler+0x8>
    275c:	rdtsc
    275e:	shl    rdx,0x20
  return pass;
    2762:	mov    QWORD PTR [rsp+0xa8],r8
    276a:	mov    QWORD PTR [rsp+0x88],0x13
    2776:	or     rax,rdx
    2779:	lea    rdx,[rip+0x1130]        # 38b0 <__func__.2>
    2780:	movq   xmm0,rax
  while (parser_incomplete(parser))
    2785:	mov    rax,QWORD PTR [rsi+0x8]
    2789:	movhps xmm0,QWORD PTR [rip+0x2a08]        # 5198 <g_profiler+0x78>
    2790:	mov    QWORD PTR [rsp+0x80],rdx
    2798:	mov    QWORD PTR [rsp+0xa0],0x2
    27a4:	movaps XMMWORD PTR [rsp+0x90],xmm0
    27ac:	cmp    QWORD PTR [rsi+0x10],rax
    27b0:	jae    29d1 <parse_json_children+0x2b1>
    27b6:	mov    DWORD PTR [rsp+0xc],ecx
    27ba:	mov    r15,rsi
  JSON_Object *current_last_child = NULL;
    27bd:	xor    r12d,r12d
  JSON_Object *first_child        = NULL;
    27c0:	xor    r14d,r14d
    27c3:	xchg   ax,ax
    27c5:	data16 cs nop WORD PTR [rax+rax*1+0x0]
    if (has_keys)
    27d0:	mov    ecx,DWORD PTR [rsp+0xc]
    JSON_Token key_token = {0};
    27d4:	pxor   xmm0,xmm0
    27d8:	mov    QWORD PTR [rsp+0x30],0x0
    JSON_Token value_token = {0};
    27e1:	mov    QWORD PTR [rsp+0x50],0x0
    JSON_Token key_token = {0};
    27ea:	movaps XMMWORD PTR [rsp+0x20],xmm0
    JSON_Token value_token = {0};
    27ef:	movaps XMMWORD PTR [rsp+0x40],xmm0
    if (has_keys)
    27f4:	test   ecx,ecx
    27f6:	je     2948 <parse_json_children+0x228>
      key_token = get_json_token(parser);
    27fc:	lea    rdi,[rsp+0x20]
    2801:	mov    rsi,r15
    2804:	call   2440 <get_json_token>
    2809:	mov    eax,DWORD PTR [rsp+0x20]
    280d:	mov    r10,QWORD PTR [rsp+0x28]
    2812:	mov    rbx,QWORD PTR [rsp+0x30]
      if (key_token.type == JSON_TOKEN_STRING)
    2817:	cmp    eax,0x7
    281a:	je     2980 <parse_json_children+0x260>
        LOG_ERROR("Unexpected key type: %s, (value = %*.s)", JSON_Token_Type_strings[key_token.type], String_Format(key_token.value));
    2820:	sub    rsp,0x8
    2824:	mov    edx,0x164
    2829:	mov    r9d,ebx
    282c:	mov    edi,0x1
    2831:	push   r10
    2833:	lea    rcx,[rip+0x2526]        # 4d60 <JSON_Token_Type_strings>
    283a:	lea    rsi,[rip+0x7c3]        # 3004 <_IO_stdin_used+0x4>
    2841:	mov    r8,QWORD PTR [rcx+rax*8]
    2845:	xor    eax,eax
    2847:	lea    rcx,[rip+0xbf2]        # 3440 <_IO_stdin_used+0x440>
    284e:	mov    QWORD PTR [rsp+0x28],r10
    2853:	call   1ff0 <log_message>
    2858:	pop    rax
    2859:	pop    rdx
    285a:	mov    r10,QWORD PTR [rsp+0x18]
    285f:	lea    rbp,[rsp+0x60]
    JSON_Token value_token = {0};
    2864:	xor    eax,eax
    2866:	cs nop WORD PTR [rax+rax*1+0x0]
    JSON_Object *object = parse_json_object(arena, parser, key_token.value, value_token);
    2870:	mov    QWORD PTR [rsp+0x30],rbx
    2875:	sub    rsp,0x20
    2879:	mov    rsi,r15
    287c:	mov    QWORD PTR [rsp+0x48],r10
    2881:	mov    DWORD PTR [rsp+0x60],eax
    2885:	movdqa xmm0,XMMWORD PTR [rsp+0x60]
    288b:	mov    rax,QWORD PTR [rsp+0x70]
    2890:	mov    rdx,QWORD PTR [rsp+0x48]
    2895:	mov    rcx,QWORD PTR [rsp+0x50]
    289a:	mov    rdi,QWORD PTR [rsp+0x30]
    289f:	movups XMMWORD PTR [rsp],xmm0
    28a3:	mov    QWORD PTR [rsp+0x10],rax
    28a8:	call   2a60 <parse_json_object>
      if (!first_child)
    28ad:	add    rsp,0x20
    JSON_Object *object = parse_json_object(arena, parser, key_token.value, value_token);
    28b1:	mov    rbx,rax
      if (!first_child)
    28b4:	test   r14,r14
    28b7:	je     2970 <parse_json_children+0x250>
        current_last_child->next_sibling = object;
    28bd:	mov    QWORD PTR [r12+0x28],rax
    JSON_Token expect_comma_or_end = get_json_token(parser);
    28c2:	mov    rsi,r15
    28c5:	mov    rdi,rbp
    28c8:	call   2440 <get_json_token>
    28cd:	mov    eax,DWORD PTR [rsp+0x60]
    if (expect_comma_or_end.type == end_token)
    28d1:	cmp    r13d,eax
    28d4:	je     29e0 <parse_json_children+0x2c0>
    else if (expect_comma_or_end.type != JSON_TOKEN_COMMA)
    28da:	cmp    eax,0x5
    28dd:	je     292c <parse_json_children+0x20c>
      LOG_ERROR("Expected comma, parsed Token :: Type = %s, Value = '%.*s', \n", JSON_Token_Type_strings[expect_comma_or_end.type],
    28df:	mov    r9,QWORD PTR [rsp+0x70]
    28e4:	sub    rsp,0x18
    28e8:	lea    rcx,[rip+0x2471]        # 4d60 <JSON_Token_Type_strings>
    28ef:	mov    edx,0x18b
    28f4:	movdqa xmm0,XMMWORD PTR [rsp+0x78]
    28fa:	mov    r8,QWORD PTR [rcx+rax*8]
    28fe:	mov    edi,0x1
    2903:	xor    eax,eax
    2905:	mov    QWORD PTR [rsp+0x10],r9
    290a:	lea    rcx,[rip+0xb57]        # 3468 <_IO_stdin_used+0x468>
    2911:	lea    rsi,[rip+0x6ec]        # 3004 <_IO_stdin_used+0x4>
    2918:	movups XMMWORD PTR [rsp],xmm0
    291c:	push   QWORD PTR [rsp+0x80]
    2923:	call   1ff0 <log_message>
    2928:	add    rsp,0x20
  while (parser_incomplete(parser))
    292c:	mov    rax,QWORD PTR [r15+0x8]
    2930:	cmp    QWORD PTR [r15+0x10],rax
    2934:	jae    29e0 <parse_json_children+0x2c0>
    293a:	mov    r12,rbx
    293d:	jmp    27d0 <parse_json_children+0xb0>
    2942:	nop    WORD PTR [rax+rax*1+0x0]
      value_token = get_json_token(parser);
    2948:	lea    rdi,[rsp+0x40]
    294d:	mov    rsi,r15
    JSON_Token key_token = {0};
    2950:	xor    ebx,ebx
      value_token = get_json_token(parser);
    2952:	call   2440 <get_json_token>
    2957:	mov    eax,DWORD PTR [rsp+0x40]
    JSON_Token key_token = {0};
    295b:	xor    r10d,r10d
    if (value_token.type == end_token)
    295e:	cmp    eax,r13d
    2961:	je     29e0 <parse_json_children+0x2c0>
    2963:	lea    rbp,[rsp+0x60]
    2968:	jmp    2870 <parse_json_children+0x150>
    296d:	nop    DWORD PTR [rax]
        first_child        = object;
    2970:	mov    r14,rax
    2973:	jmp    28c2 <parse_json_children+0x1a2>
    2978:	nop    DWORD PTR [rax+rax*1+0x0]
        JSON_Token expect_colon = get_json_token(parser);
    2980:	lea    rbp,[rsp+0x60]
    2985:	mov    rsi,r15
    2988:	mov    QWORD PTR [rsp+0x18],r10
    298d:	mov    rdi,rbp
    2990:	call   2440 <get_json_token>
        if (expect_colon.type == JSON_TOKEN_COLON)
    2995:	cmp    DWORD PTR [rsp+0x60],0x6
    299a:	je     2a40 <parse_json_children+0x320>
          LOG_ERROR("Expected colon after key: %*.s", String_Format(key_token.value));
    29a0:	mov    r9,QWORD PTR [rsp+0x18]
    29a5:	mov    r8d,ebx
    29a8:	mov    edx,0x15f
    29ad:	xor    eax,eax
    29af:	lea    rcx,[rip+0xa6a]        # 3420 <_IO_stdin_used+0x420>
    29b6:	lea    rsi,[rip+0x647]        # 3004 <_IO_stdin_used+0x4>
    29bd:	mov    edi,0x1
    29c2:	call   1ff0 <log_message>
    if (value_token.type == end_token)
    29c7:	mov    r10,QWORD PTR [rsp+0x18]
    29cc:	jmp    2864 <parse_json_children+0x144>
  JSON_Object *first_child        = NULL;
    29d1:	xor    r14d,r14d
    29d4:	nop
    29d5:	data16 cs nop WORD PTR [rax+rax*1+0x0]
  profile_end_func();
    29e0:	sub    rsp,0x30
    29e4:	movdqa xmm0,XMMWORD PTR [rsp+0xb0]
    29ed:	movups XMMWORD PTR [rsp],xmm0
    29f1:	movdqa xmm0,XMMWORD PTR [rsp+0xc0]
    29fa:	movups XMMWORD PTR [rsp+0x10],xmm0
    29ff:	movdqa xmm0,XMMWORD PTR [rsp+0xd0]
    2a08:	movups XMMWORD PTR [rsp+0x20],xmm0
    2a0d:	call   1e40 <__profile_end_pass>
  return first_child;
    2a12:	add    rsp,0x30
}
    2a16:	mov    rax,QWORD PTR [rsp+0xb8]
    2a1e:	sub    rax,QWORD PTR fs:0x28
    2a27:	jne    2a5b <parse_json_children+0x33b>
    2a29:	add    rsp,0xc8
    2a30:	mov    rax,r14
    2a33:	pop    rbx
    2a34:	pop    rbp
    2a35:	pop    r12
    2a37:	pop    r13
    2a39:	pop    r14
    2a3b:	pop    r15
    2a3d:	ret
    2a3e:	xchg   ax,ax
          value_token = get_json_token(parser);
    2a40:	lea    rdi,[rsp+0x40]
    2a45:	mov    rsi,r15
    2a48:	call   2440 <get_json_token>
    2a4d:	mov    eax,DWORD PTR [rsp+0x40]
    2a51:	mov    r10,QWORD PTR [rsp+0x18]
    2a56:	jmp    295e <parse_json_children+0x23e>
}
    2a5b:	call   1060 <__stack_chk_fail@plt>

0000000000002a60 <parse_json_object>:
{
    2a60:	push   r13
    2a62:	mov    r9,rdi
    2a65:	mov    r13,rcx
    2a68:	mov    rdi,rsi
    2a6b:	push   r12
    2a6d:	mov    r12,rdx
    2a70:	push   rbx
    2a71:	sub    rsp,0x40
    .parent_index = g_profiler.current_parent_zone,
    2a75:	mov    rsi,QWORD PTR [rip+0x26ac]        # 5128 <g_profiler+0x8>
  g_profiler.current_parent_zone = zone_index;
    2a7c:	mov    QWORD PTR [rip+0x26a1],0x1        # 5128 <g_profiler+0x8>
    2a87:	mov    ecx,DWORD PTR [rsp+0x60]
    2a8b:	rdtsc
  return pass;
    2a8d:	lea    rbx,[rip+0xe3c]        # 38d0 <__func__.3>
    2a94:	shl    rdx,0x20
    2a98:	mov    QWORD PTR [rsp+0x10],rbx
    2a9d:	or     rax,rdx
    2aa0:	mov    QWORD PTR [rsp+0x38],rsi
    first_child = parse_json_children(arena, parser, JSON_TOKEN_CLOSE_CURLY_BRACE, has_keys);
    2aa5:	mov    edx,0x2
    2aaa:	mov    QWORD PTR [rsp+0x18],0x11
    2ab3:	movq   xmm0,rax
    2ab8:	movhps xmm0,QWORD PTR [rip+0x26b1]        # 5170 <g_profiler+0x50>
    2abf:	mov    QWORD PTR [rsp+0x30],0x1
    2ac8:	movaps XMMWORD PTR [rsp+0x20],xmm0
  if (token.type == JSON_TOKEN_OPEN_CURLY_BRACE)
    2acd:	cmp    ecx,0x1
    2ad0:	je     2ba7 <parse_json_object+0x147>
  else if (token.type == JSON_TOKEN_OPEN_SQUARE_BRACE)
    2ad6:	cmp    ecx,0x3
    2ad9:	je     2ba0 <parse_json_object+0x140>
  b32 is_value_type = (type == JSON_TOKEN_STRING ||
    2adf:	lea    eax,[rcx-0x7]
                       type == JSON_TOKEN_NULL   ||
    2ae2:	cmp    eax,0x4
    2ae5:	ja     2b58 <parse_json_object+0xf8>
  JSON_Object *first_child = NULL;
    2ae7:	xor    ebx,ebx
  JSON_Object *result  = arena_new(arena, JSON_Object);
    2ae9:	mov    rdi,r9
    2aec:	mov    edx,0x8
    2af1:	mov    esi,0x30
    2af6:	call   2270 <arena_alloc>
  result->value        = token.value;
    2afb:	movdqu xmm0,XMMWORD PTR [rsp+0x68]
  profile_end_func();
    2b01:	sub    rsp,0x30
  result->key          = key;
    2b05:	mov    QWORD PTR [rax],r12
  JSON_Object *result  = arena_new(arena, JSON_Object);
    2b08:	mov    r9,rax
  result->value        = token.value;
    2b0b:	movups XMMWORD PTR [rax+0x10],xmm0
  profile_end_func();
    2b0f:	movdqa xmm0,XMMWORD PTR [rsp+0x40]
  result->key          = key;
    2b15:	mov    QWORD PTR [rax+0x8],r13
  result->first_child  = first_child;
    2b19:	mov    QWORD PTR [rax+0x20],rbx
  result->next_sibling = NULL;
    2b1d:	mov    QWORD PTR [rax+0x28],0x0
  profile_end_func();
    2b25:	movups XMMWORD PTR [rsp],xmm0
    2b29:	movdqa xmm0,XMMWORD PTR [rsp+0x50]
    2b2f:	movups XMMWORD PTR [rsp+0x10],xmm0
    2b34:	movdqa xmm0,XMMWORD PTR [rsp+0x60]
    2b3a:	movups XMMWORD PTR [rsp+0x20],xmm0
    2b3f:	call   1e40 <__profile_end_pass>
}
    2b44:	add    rsp,0x70
    2b48:	mov    rax,r9
    2b4b:	pop    rbx
    2b4c:	pop    r12
    2b4e:	pop    r13
    2b50:	ret
    2b51:	nop    DWORD PTR [rax+0x0]
    2b58:	mov    QWORD PTR [rsp+0x8],r9
    LOG_ERROR("Unexpected token type encountered while parsing json object: %s, (value = %.*s)", JSON_Token_Type_strings[token.type], token.value);
    2b5d:	lea    rax,[rip+0x21fc]        # 4d60 <JSON_Token_Type_strings>
    2b64:	mov    edx,0x134
    2b69:	lea    rsi,[rip+0x494]        # 3004 <_IO_stdin_used+0x4>
    2b70:	push   QWORD PTR [rsp+0x70]
    2b74:	mov    r8,QWORD PTR [rax+rcx*8]
    2b78:	mov    edi,0x1
    2b7d:	xor    eax,eax
    2b7f:	push   QWORD PTR [rsp+0x70]
    2b83:	lea    rcx,[rip+0x91e]        # 34a8 <_IO_stdin_used+0x4a8>
    2b8a:	call   1ff0 <log_message>
    2b8f:	pop    rax
    2b90:	pop    rdx
    2b91:	mov    r9,QWORD PTR [rsp+0x8]
    2b96:	jmp    2ae7 <parse_json_object+0x87>
    2b9b:	nop    DWORD PTR [rax+rax*1+0x0]
    first_child = parse_json_children(arena, parser, JSON_TOKEN_CLOSE_SQUARE_BRACE, has_keys);
    2ba0:	xor    ecx,ecx
    2ba2:	mov    edx,0x4
    2ba7:	mov    rsi,rdi
    2baa:	mov    rdi,r9
    2bad:	mov    QWORD PTR [rsp+0x8],r9
    2bb2:	call   2720 <parse_json_children>
    2bb7:	mov    r9,QWORD PTR [rsp+0x8]
    2bbc:	mov    rbx,rax
    2bbf:	jmp    2ae9 <parse_json_object+0x89>
    2bc4:	nop
    2bc5:	data16 cs nop WORD PTR [rax+rax*1+0x0]

0000000000002bd0 <json_token_type_is_value_type>:
  b32 is_value_type = (type == JSON_TOKEN_STRING ||
    2bd0:	sub    edi,0x7
                       type == JSON_TOKEN_NULL   ||
    2bd3:	xor    eax,eax
    2bd5:	cmp    edi,0x4
    2bd8:	setbe  al
}
    2bdb:	ret
    2bdc:	nop    DWORD PTR [rax+0x0]

0000000000002be0 <json_object_to_f64>:
  ASSERT(object, "Must pass valid object to f64 conversion");
    2be0:	test   rdi,rdi
    2be3:	je     1234 <json_object_to_f64.cold>

  String val = object->value;
    2be9:	mov    rcx,QWORD PTR [rdi+0x18]
  // Get sign.
  usize at = 0;

  f64 sign = 1.0;
  if (val.count > at && val.data[at] == '-')
    2bed:	pxor   xmm0,xmm0
    2bf1:	test   rcx,rcx
    2bf4:	je     2c7f <json_object_to_f64+0x9f>
  String val = object->value;
    2bfa:	mov    rsi,QWORD PTR [rdi+0x10]
  if (val.count > at && val.data[at] == '-')
    2bfe:	cmp    BYTE PTR [rsi],0x2d
    2c01:	je     2c80 <json_object_to_f64+0xa0>
  f64 sign = 1.0;
    2c03:	movsd  xmm4,QWORD PTR [rip+0xd65]        # 3970 <__PRETTY_FUNCTION__.9+0x20>
  usize at = 0;
    2c0b:	xor    edx,edx
  {
    u8 digit = val.data[at] - (u8)'0';
    if (digit < 10)
    {
      // We go left to right so each previous result is 10 times bigger
      result = 10 * result + (f64)digit;
    2c0d:	movsd  xmm2,QWORD PTR [rip+0xd73]        # 3988 <__PRETTY_FUNCTION__.9+0x38>
  f64 result = 0.0;
    2c15:	pxor   xmm0,xmm0
    2c19:	jmp    2c5c <json_object_to_f64+0x7c>
    2c1b:	nop    DWORD PTR [rax+0x0]
    2c1f:	data16 cs nop WORD PTR [rax+rax*1+0x0]
    2c2a:	data16 cs nop WORD PTR [rax+rax*1+0x0]
    2c35:	data16 cs nop WORD PTR [rax+rax*1+0x0]
      result = 10 * result + (f64)digit;
    2c40:	mulsd  xmm0,xmm2
    2c44:	movzx  eax,al
    2c47:	pxor   xmm1,xmm1
      at += 1;
    2c4b:	add    rdx,0x1
      result = 10 * result + (f64)digit;
    2c4f:	cvtsi2sd xmm1,eax
    2c53:	addsd  xmm0,xmm1
  while (at < val.count)
    2c57:	cmp    rdx,rcx
    2c5a:	jae    2c72 <json_object_to_f64+0x92>
    u8 digit = val.data[at] - (u8)'0';
    2c5c:	movzx  eax,BYTE PTR [rsi+rdx*1]
    2c60:	sub    eax,0x30
    if (digit < 10)
    2c63:	cmp    al,0x9
    2c65:	jbe    2c40 <json_object_to_f64+0x60>
      break;
    }
  }

  // After decimal (if there)
  if (at < val.count && val.data[at] == '.')
    2c67:	cmp    rdx,rcx
    2c6a:	jae    2c72 <json_object_to_f64+0x92>
    2c6c:	cmp    BYTE PTR [rsi+rdx*1],0x2e
    2c70:	je     2ca0 <json_object_to_f64+0xc0>
        break;
      }
    }
  }

  return sign * result;
    2c72:	mulsd  xmm0,xmm4
    2c76:	ret
  while (at < val.count)
    2c77:	movsd  xmm0,QWORD PTR [rip+0xd01]        # 3980 <__PRETTY_FUNCTION__.9+0x30>
}
    2c7f:	ret
  while (at < val.count)
    2c80:	cmp    rcx,0x1
    2c84:	je     2c77 <json_object_to_f64+0x97>
    2c86:	movsd  xmm4,QWORD PTR [rip+0xcda]        # 3968 <__PRETTY_FUNCTION__.9+0x18>
    2c8e:	mov    edx,0x1
    2c93:	jmp    2c0d <json_object_to_f64+0x2d>
    2c98:	nop    DWORD PTR [rax+rax*1+0x0]
    at += 1;
    2ca0:	add    rdx,0x1
    while (at < val.count)
    2ca4:	cmp    rdx,rcx
    2ca7:	jae    2c72 <json_object_to_f64+0x92>
    f64 factor = 1.0 / 10.0;
    2ca9:	movsd  xmm3,QWORD PTR [rip+0xcc7]        # 3978 <__PRETTY_FUNCTION__.9+0x28>
    2cb1:	movapd xmm2,xmm3
    2cb5:	jmp    2ce0 <json_object_to_f64+0x100>
    2cb7:	nop    WORD PTR [rax+rax*1+0x0]
        result = result + factor * (f64)digit;
    2cc0:	movzx  eax,al
    2cc3:	pxor   xmm1,xmm1
        at += 1;
    2cc7:	add    rdx,0x1
        result = result + factor * (f64)digit;
    2ccb:	cvtsi2sd xmm1,eax
    2ccf:	mulsd  xmm1,xmm2
        factor *= 1.0 / 10.0;
    2cd3:	mulsd  xmm2,xmm3
        result = result + factor * (f64)digit;
    2cd7:	addsd  xmm0,xmm1
    while (at < val.count)
    2cdb:	cmp    rdx,rcx
    2cde:	jae    2c72 <json_object_to_f64+0x92>
      u8 digit = val.data[at] - (u8)'0';
    2ce0:	movzx  eax,BYTE PTR [rsi+rdx*1]
    2ce4:	sub    eax,0x30
      if (digit < 10)
    2ce7:	cmp    al,0x9
    2ce9:	jbe    2cc0 <json_object_to_f64+0xe0>
    2ceb:	jmp    2c72 <json_object_to_f64+0x92>

Disassembly of section .fini:

0000000000002cf0 <_fini>:
    2cf0:	endbr64
    2cf4:	sub    rsp,0x8
    2cf8:	add    rsp,0x8
    2cfc:	ret
