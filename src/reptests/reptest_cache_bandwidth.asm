global read_region_asm
global read_mask_asm

section .text

; Linux calling convention. Region repeat (total amount) count in rdi, pointer in rsi,
; region/512 (how many times to execute the inner loopt, the region) count in rdx

read_region_asm:
  mov rax, rsi ; rax will hold base pointer
  mov r9, rdx  ; r9 will hold the inner count
  align 64
.outer:
  mov rsi, rax ; reset the base pointer
  mov rdx, r9  ; reset the inner count

.inner:
  ; Issue 512 bytes of loads to make absolutely sure that the load is
  ; the bottleneck here, on my micro-architecture (golden-cove) we may issue 3 loads per cycle
  ; The masking arithmetic takes 3 cycles so we need at least 9 loads,
  ; so round up to 16 to keep the power 2 and modulo.
  vmovdqu ymm0, [rsi]
  vmovdqu ymm0, [rsi + 32]
  vmovdqu ymm0, [rsi + 64]
  vmovdqu ymm0, [rsi + 96]
  vmovdqu ymm0, [rsi + 128]
  vmovdqu ymm0, [rsi + 160]
  vmovdqu ymm0, [rsi + 192]
  vmovdqu ymm0, [rsi + 224]
  vmovdqu ymm0, [rsi + 256]
  vmovdqu ymm0, [rsi + 288]
  vmovdqu ymm0, [rsi + 320]
  vmovdqu ymm0, [rsi + 352]
  vmovdqu ymm0, [rsi + 384]
  vmovdqu ymm0, [rsi + 416]
  vmovdqu ymm0, [rsi + 448]
  vmovdqu ymm0, [rsi + 480]

  ; Increase the offset
  add rsi, 512

  sub rdx, 1
  jnz .inner

  sub rdi, 1
  jnz .outer

  ret

; Linux calling convention. Count in rdi, pointer in rsi, mask in rdx

read_mask_asm:
  xor rcx, rcx
  mov rax, rsi
  align 64
.loop:
  ; Issue 512 bytes of loads to make absolutely sure that the load is
  ; the bottleneck here, on my micro-architecture (golden-cove) we may issue 3 loads per cycle
  ; The masking arithmetic takes 3 cycles so we need at least 9 loads,
  ; so round up to 16 to keep the power 2 and modulo.
  vmovdqu ymm0, [rsi]
  vmovdqu ymm0, [rsi + 32]
  vmovdqu ymm0, [rsi + 64]
  vmovdqu ymm0, [rsi + 96]
  vmovdqu ymm0, [rsi + 128]
  vmovdqu ymm0, [rsi + 160]
  vmovdqu ymm0, [rsi + 192]
  vmovdqu ymm0, [rsi + 224]
  vmovdqu ymm0, [rsi + 256]
  vmovdqu ymm0, [rsi + 288]
  vmovdqu ymm0, [rsi + 320]
  vmovdqu ymm0, [rsi + 352]
  vmovdqu ymm0, [rsi + 384]
  vmovdqu ymm0, [rsi + 416]
  vmovdqu ymm0, [rsi + 448]
  vmovdqu ymm0, [rsi + 480]

  add rcx, 512
  and rcx, rdx ; Only up to 8kb

  mov rsi, rax
  add rsi, rcx

  sub rdi, 512
  jnz .loop
  ret
