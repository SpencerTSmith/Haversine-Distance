global rat_add_asm
global rat_mov_add_asm

section .text

rat_add_asm:
align 64
  xor rcx, rcx
  mov rax, 1000000000
.loop:
  add rcx, 1
  add rcx, 1
  dec rax
  jnz .loop
  ret

rat_mov_add_asm:
align 64
  xor rcx, rcx
  mov rax, 1000000000
.loop:
  mov rcx, rax
  add rcx, 1
  mov rcx, rax
  add rcx, 1
  dec rax
  jnz .loop
  ret
