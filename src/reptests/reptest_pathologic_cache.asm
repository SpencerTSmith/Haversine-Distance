global read_pathologic_asm

section .text

; Linux calling convention. Repeat count in rdi, pointer in rsi,
; inner count in rdx (how many cache lines to read)
; read spacing in rcx, set to cache index bit size to cause pathologic cache behavior

read_pathologic_asm:
  mov rax, rsi ; rax will hold base pointer
  mov r9, rdx  ; r9 will hold the inner count
  align 64
.outer:
  mov rsi, rax ; reset the base pointer
  mov rdx, r9  ; reset the inner count

.inner:
  vmovdqu ymm0, [rsi]
  vmovdqu ymm0, [rsi + 32]

  ; Increase the offset by read spacing
  add rsi, rcx

  sub rdx, 1
  jnz .inner

  sub rdi, 1
  jnz .outer

  ret
