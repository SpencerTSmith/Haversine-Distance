global readL1_asm
global readL2_asm
global readL3_asm

section .text

; Count in rdi, pointer in rsi

readL1_asm:
  xor rax, rax
  xor rcx, rcx
  align 64
.loop:
  vmovdqu ymm0, [rsi]
  vmovdqu ymm0, [rsi + 32]
  vmovdqu ymm0, [rsi + 64]
  vmovdqu ymm0, [rsi + 96]
  vmovdqu ymm0, [rsi + 128]
  vmovdqu ymm0, [rsi + 160]
  vmovdqu ymm0, [rsi + 192]
  vmovdqu ymm0, [rsi + 224]

  add rcx, 1
  and rcx, 0x20000 ; Only up to 16kb
  add rsi, rcx

  sub rdi, 256
  cmp rdi, rax
  jne .loop

readL2_asm:
  xor rax, rax
  xor rcx, rcx
  align 64
.loop:
  vmovdqu ymm0, [rsi]
  vmovdqu ymm0, [rsi + 32]
  vmovdqu ymm0, [rsi + 64]
  vmovdqu ymm0, [rsi + 96]
  vmovdqu ymm0, [rsi + 128]
  vmovdqu ymm0, [rsi + 160]
  vmovdqu ymm0, [rsi + 192]
  vmovdqu ymm0, [rsi + 224]

  add rcx, 1
  and rcx, 0x2000000 ; Only up to 4mb
  add rsi, rcx

  sub rdi, 256
  cmp rdi, rax
  jne .loop

readL3_asm:
  xor rax, rax
  xor rcx, rcx
  align 64
.loop:
  vmovdqu ymm0, [rsi]
  vmovdqu ymm0, [rsi + 32]
  vmovdqu ymm0, [rsi + 64]
  vmovdqu ymm0, [rsi + 96]
  vmovdqu ymm0, [rsi + 128]
  vmovdqu ymm0, [rsi + 160]
  vmovdqu ymm0, [rsi + 192]
  vmovdqu ymm0, [rsi + 224]

  add rcx, 1
  and rcx, 0x8000000 ; Only up to 16mb
  add rsi, rcx

  sub rdi, 256
  cmp rdi, rax
  jne .loop
