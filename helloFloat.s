
.data
   format:  .asciz "%f\n"
   a: .double  53427.35236
   b: .int 5

.text
  .global main

  
main:    
  endbr64    
  push    %rbp
  mov    %rsp, %rbp
 # subq    $0x10, %rsp
  movsd a(%rip), %xmm0
  cvttsd2si %xmm0,%eax
  mov %eax, %esi
  lea  format(%rip), %rdi
 # xor    %rax, %rax
  callq    printf

 movq    $0x0, %rax
 addq    $0x10, %rsp
  nop
  pop    %rbp
  retq    

