
.data
format:  .asciz "%ld\n"

.text
  .global main

  
main:    
  endbr64    
  pushq    %rbp
  movq    %rsp, %rbp
  subq    $0x60, %rsp
  leaq    -0x18(%rbp), %r10
  movq    %r10, -0x8(%rbp)
  movq    -0x8(%rbp), %r10
  movq    $0x8, %r11
  addq    %r10, %r11
  movq    %r11, -0x10(%rbp)
  movq    -0x10(%rbp), %r10
  movq    %r10, -0x18(%rbp)

  mov    -0x18(%rbp), %rsi
# mov    %r10d, %esi
  lea format(%rip), %rdi
  xor  %eax, %eax
  callq printf
  

  
  movq    $0x8, -0x44(%rbp)
  movq    -0x44(%rbp), %r10
  movq    $0x5, %r11
  imulq    %r10, %r11
  movq    %r11, -0x4c(%rbp)
  movq    -0x18(%rbp), %r10
  movq    -0x4c(%rbp), %r11
  addq    %r10, %r11
  movq    %r11, -0x58(%rbp)
  movq    -0x58(%rbp), %r10
  movq    $0x7, (%r10)

  mov    %r10, %rsi
# mov    %r10d, %esi
  lea format(%rip), %rdi
  xor  %eax, %eax
  callq printf


  mov    $0x0, %eax
  add    $0x60, %rsp
  pop    %rbp
  retq    

