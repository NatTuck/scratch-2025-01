    .global main

    .text
add2:
    enter $0, $0
    
    mov %rdi, %rax

    add $2, %rax

    leave
    ret

main:
    enter $0, $0

    mov $5, %rdi
    call add2

    mov $long_fmt, %rdi
    mov %rax, %rsi
    mov $0, %al
    call printf

    leave
    ret

    .data
long_fmt: .string "%ld\n"



