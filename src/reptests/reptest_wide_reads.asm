global read32_asm
global read64_asm
global read128_asm
global read256_asm
global read512_asm

section .text

read32_asm:
  align 64
.loop:
  mov r9d, [rsi]
  mov r9d, [rsi + 4]
  sub rdi, 4
  jnle .loop
  ret

read64_asm:
  align 64
.loop:
  mov r9, [rsi]
  mov r9, [rsi + 8]
  sub rdi, 8
  jnle .loop
  ret

read128_asm:
  align 64
.loop:
  vmovdqu xmm0, [rsi]
  vmovdqu xmm1, [rsi + 16]
  sub rdi, 16
  jnle .loop
  ret

read256_asm:
  align 64
.loop:
  vmovdqu ymm0, [rsi]
  vmovdqu ymm1, [rsi + 32]
  sub rdi, 32
  jnle .loop
  ret

; read512_asm:
;   align 64
; .loop:
;   vmovdqu zmm0, [rsi]
;   vmovdqu zmm1, [rsi + 64]
;   sub rdi, 1
;   jnle .loop
;   ret
