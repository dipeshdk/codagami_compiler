   .data
format:  .asciz "%d\n"
.text
    .global main   
 
main:    
    endbr64 
    push   %rbp
    mov    %rsp,%rbp
    lea format(%rip), %rdi
    movl   $0x5,-0x4(%rbp)
    mov  -0x4(%rbp), %esi
    xor  %eax, %eax
    call printf
    pop    %rbp
    ret 
