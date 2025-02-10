    .global getmem

getmem:
    push %rbx // how many bytes requested
    push %r12 // old brk
    enter $0, $0

    mov %rdi, %rbx  // how many bytes requested

    mov $12, %rax  // sys_brk
    mov $0, %rdi   // invalid value
    syscall

    mov %rax, %r12   // returns old brk, for our return value
    mov %rax, %rdi   // old brk, to calculated requested new break

    mov $12, %rax
    add %rbx, %rdi   // calculate new break (old + first arg)
    syscall

    mov %r12, %rax

    leave
    pop %r12
    pop %rbx
    ret
