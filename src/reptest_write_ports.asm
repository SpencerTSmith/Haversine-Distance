global write1_asm
global write2_asm
global write3_asm
global write4_asm

section .text

write1_asm:
  align 64
.loop:
  mov [rsi], rax
  sub rdi, 1
  jnle .loop
  ret

write2_asm:
  align 64
.loop:
  mov [rsi], rax
  mov [rsi], rax
  sub rdi, 2
  jnle .loop
  ret

write3_asm:
  align 64
.loop:
  mov [rsi], rax
  mov [rsi], rax
  mov [rsi], rax
  sub rdi, 3
  jnle .loop
  ret

write4_asm:
  align 64
.loop:
  mov [rsi], rax
  mov [rsi], rax
  mov [rsi], rax
  mov [rsi], rax
  sub rdi, 4
  jnle .loop
  ret
