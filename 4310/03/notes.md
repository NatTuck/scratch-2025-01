
## AMD64 Archetecture / Assembly

Registers: rax, rcx , rbx, rdi, rsi, rbp, r9, ..., r15
Size variants: rax, eax, ax, ah/al

Calling convention:

 - arguments go in, in order: rdi, rsi, rdx, rcx, r8, r9
 - return value comes out in rax
 - (second return is in rdx)
 - To call varargs, you must first zero %al
