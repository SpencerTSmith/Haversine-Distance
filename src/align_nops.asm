global nop_aligned64_asm
global nop_aligned1_asm
global nop_aligned15_asm
global nop_aligned31_asm
global nop_aligned63_asm

section .text

; For 64 bit linux calling convention, in which buffer count is 1st arg in RDI, and 2nd arg is data pointer in RSI

nop_aligned64_asm:
  xor rax, rax
  align 64
  .loop:
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop_aligned1_asm:
  xor rax, rax
  align 64
  nop
  .loop:
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop_aligned15_asm:
  xor rax, rax
  align 64
  %rep 15
  nop
  %endrep
  .loop:
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop_aligned31_asm:
  xor rax, rax
  align 64
  %rep 31
  nop
  %endrep
  .loop:
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop_aligned63_asm:
  xor rax, rax
  align 64
  %rep 63
  nop
  %endrep
  .loop:
    inc rax
    cmp rax, rdi
    jne .loop
  ret
