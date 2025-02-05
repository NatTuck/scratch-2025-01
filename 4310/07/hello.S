    .global main
    .data
hello: .string "hello\n"

    .text
main:
    enter $0, $0

    mov $1, %rax        // write syscall
    mov $1, %rdi        // fd = 1 = stdout
    mov $hello, %rsi     // buf
    mov $6, %rdx
    syscall

    mov $0, %rax        // return 0
    leave
    ret
