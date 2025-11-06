global branch_bytes_asm

branch_bytes_asm:
  xor rax, rax
  .loop:
    mov r8, [rsi + rax]
    inc rax
    test r8, 1
    jnz .skip
    nop
  .skip:
    cmp rax, rdi
    jne .loop
    ret
