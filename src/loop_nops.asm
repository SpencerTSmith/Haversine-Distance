global nop1x3_all_bytes_asm
global nop3x1_all_bytes_asm
global nop9x1_all_bytes_asm
global nop32x1_all_bytes_asm

section .text

; For 64 bit linux calling convention, in which buffer count is 1st arg in RDI, and 2nd arg is data pointer in RSI

nop1x3_all_bytes_asm:
  xor rax, rax
  .loop:
    db 0x0f, 0x1f, 0x00 ; 3 byte nop to match the other 3 byte instruction we are replacing
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop3x1_all_bytes_asm:
  xor rax, rax
  .loop:
    nop
    nop
    nop
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop9x1_all_bytes_asm:
  xor rax, rax
  .loop:
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop32x1_all_bytes_asm:
  xor rax, rax
  .loop:
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    inc rax
    cmp rax, rdi
    jne .loop
  ret
