
.data
   format:  .asciz "%lf\n"
   a: .double  -0.2
   d2: .double 5000.5
   b: .int 5

.text
  .global main

  
main:    
  endbr64    
  push    %rbp
  mov    %rsp, %rbp
  subq    $0x10, %rsp
 # movsd a(%rip), %xmm0
 # addsd %xmm0, %xmm0
 # movsd %xmm0, a(%rip)
  
 # movsd a(%rip), %xmm0
 # movsd d2(%rip), %xmm1
 # subsd %xmm1, %xmm0
 # movsd %xmm1, d2(%rip)
 # movsd %xmm0, a(%rip)

  movsd a(%rip), %xmm0
  cvttsd2siq %xmm0,%rax
  movq %rax, %rsi
  lea  format(%rip), %rdi
 # xor    %rax, %rax
  callq    printf

 # movq    $0x0, %rax
  addq    $0x10, %rsp
  nop
  pop    %rbp
  retq    

