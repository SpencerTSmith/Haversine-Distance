global read_mask_asm
; These are just best-guesses, probably use the above to exhaustively test
global readL1_asm
global readL2_asm
global readL3_asm
global readMM_asm

section .text

; Linux calling convention. Count in rdi, pointer in rsi, mask in rdx

read_mask_asm:
  xor rcx, rcx
  mov rax, rsi
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

  add rcx, 256
  and rcx, rdx ; Only up to 8kb

  mov rsi, rax
  add rsi, rcx

  sub rdi, 256
  jnz .loop
  ret

readL1_asm:
  xor rcx, rcx
  mov rax, rsi
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

  add rcx, 256
  and rcx, 0x1fff ; Only up to 8kb

  mov rsi, rax
  add rsi, rcx

  sub rdi, 256
  jnz .loop
  ret

readL2_asm:
  xor rcx, rcx
  mov rax, rsi
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

  add rcx, 256
  and rcx, 0xFFFFF ; Only up to 1mb

  mov rsi, rax
  add rsi, rcx

  sub rdi, 256
  jnz .loop
  ret

readL3_asm:
  xor rcx, rcx
  mov rax, rsi
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

  add rcx, 256
  and rcx, 0xFFFFFF ; Only up to 16mb

  mov rsi, rax
  add rsi, rcx

  sub rdi, 256
  jnz .loop
  ret

readMM_asm:
  xor rcx, rcx
  mov rax, rsi
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

  add rcx, 256
  ; No mask, read the whole 1 GB, should be main memory, unless caches get much bigger

  mov rsi, rax
  add rsi, rcx

  sub rdi, 256
  jnz .loop
  ret
