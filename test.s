   .data
format:  .asciz "%d\n"
.text
    .global main   
 
# function call without using reg to send args
# using printf

main:    
    # begin func
    endbr64 
    push   %rbp
    mov    %rsp,%rbp
    
    # foo() call
    mov  $0x5, %rsi
    push    %rsi
    callq    foo
    pop     %rsi
    
    # a(say) = malloc(100)
    mov $0x64, %edi
    callq malloc
    mov %rax, -0x8(%rbp)
    mov    -0x8(%rbp), %rbx

    # a[0] = 16
    movl   $0x10,(%rax)

    # printf("%d\n", a[0])
    mov    -0x8(%rbp),%rax
    mov    (%rax),%eax
    mov    %eax,%esi
    lea format(%rip), %rdi
    xor  %eax, %eax
    callq printf

    # end func
    pop    %rbp
    retq


foo:
    endbr64
    push   %rbp
    mov    %rsp,%rbp
    mov     0x10(%rbp), %eax
    pop     %rbp
    retq
