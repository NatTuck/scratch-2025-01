    .global myopen

myopen:
    enter $0, $0

    mov $2, %rax
    // args 1 and 2 at least
    // are already in %rdi, %rsi
    syscall

    leave
    ret
