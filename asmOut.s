
.data
   format:  .asciz "%lf\n"
   name:  .asciz "file.txt"
   type:  .asciz "w+"
   inp: .asciz "This is testing for fprintf...\n"
   a: .double  -0.2
   d2: .double 5000.5
   b: .int 5

.text
  .global main

  
main:    
  endbr64    
  push    %rbp
  mov    %rsp, %rbp
  subq    $32, %rsp

 # fopen
  lea type(%rip), %rsi
  lea name(%rip), %rdi
  movq $0, %rax
  callq fopen
  # cltq
  movq %rax, -8(%rbp)
  movq -8(%rbp), %rax

  # fp arg
  movq %rax, %rdi
  lea    inp(%rip),%rsi 
  callq fprintf


  addq    $32, %rsp
  leaveq
  retq    

