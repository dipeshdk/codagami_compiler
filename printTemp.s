format:  .asciz "%d\n"

mov    -0x4(%rbp),%esi
lea format(%rip), %rdi
xor  %eax, %eax
callq printf