   .data
format:  .asciz "%d\n"
.text
    .global main   
 
# function call without using reg to send args
# using printf

main:    
    endbr64 
    push   %rbp
    mov    %rsp,%rbp
    lea format(%rip), %rdi
    
    mov  $0x5, %rsi
    push    %rsi
    callq    foo
    pop     %rsi

    
    movl   %eax,-0x4(%rbp)
    mov  -0x4(%rbp), %esi
    xor  %eax, %eax
    callq printf
    pop    %rbp
    retq


foo:
    endbr64
    push   %rbp
    mov    %rsp,%rbp
    mov     0x10(%rbp), %eax
    pop     %rbp
    retq
