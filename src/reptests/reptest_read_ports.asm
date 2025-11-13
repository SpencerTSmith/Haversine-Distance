global read1_asm
global read2_asm
global read3_asm
global read3real_asm
global read4_asm
global read1x2_asm
global read8x2_asm

section .text

read1_asm:
  align 64
.loop:
  mov rax, [rsi]
  sub rdi, 1
  jnle .loop
  ret

read2_asm:
  align 64
.loop:
  mov rax, [rsi]
  mov rax, [rsi]
  sub rdi, 2
  jnle .loop
  ret

read3_asm:
  align 64
.loop:
  mov rax, [rsi]
  mov rax, [rsi]
  mov rax, [rsi]
  sub rdi, 3
  jnle .loop
  ret

read3real_asm:
  align 64
.loop:
  mov rax, [rsi]
  mov rax, [rsi + 32]
  mov rax, [rsi + 64]
  sub rdi, 3
  jnle .loop
  ret

read4_asm:
  align 64
.loop:
  mov rax, [rsi]
  mov rax, [rsi]
  mov rax, [rsi]
  mov rax, [rsi]
  sub rdi, 4
  jnle .loop
  ret

read1x2_asm:
  align 64
.loop:
  mov al, [rsi]
  mov al, [rsi]
  sub rdi, 2
  jnle .loop
  ret

read8x2_asm:
  align 64
.loop:
  mov rax, [rsi]
  mov rax, [rsi]
  sub rdi, 2
  jnle .loop
  ret
