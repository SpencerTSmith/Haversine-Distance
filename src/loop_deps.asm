global mov_all_bytes_asm
global nop_all_bytes_asm
global cmp_all_bytes_asm
global dec_all_bytes_asm

section .text

; For 64 bit linux calling convention, in which buffer count is 1st arg in RDI, and 2nd arg is data pointer in RSI

mov_all_bytes_asm:
  xor rax, rax
  .loop:
    mov [rsi + rax], al
    inc rax
    cmp rax, rdi
    jne .loop
  ret

nop_all_bytes_asm:
  xor rax, rax
  .loop:
    db 0x0f, 0x1f, 0x00 ; 3 byte nop to match the other 3 byte instruction we are replacing
    inc rax
    cmp rax, rdi
    jne .loop
  ret

cmp_all_bytes_asm:
  xor rax, rax
  .loop:
    inc rax
    cmp rax, rdi
    jne .loop
  ret

dec_all_bytes_asm:
  .loop:
    dec rdi
    jnz .loop
  ret
