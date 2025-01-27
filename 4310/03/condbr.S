
// User inputs a number, x
// if x > 10:
//   print "bigger"
// else:
//   print "smaller"

    .global main
    .text
main:
    enter $8, $0

    mov $prompt, %rdi
    call puts

    mov $long_fmt, %rdi
    mov $0, %al
    lea 0(%rsp), %rsi
    call scanf

    mov 0(%rsp), %rax
    cmp $10, %rax
    jle smaller_than_ten

not_smaller_than_ten:
    mov $bigger, %rdi
    jmp main_done

smaller_than_ten:
    mov $smaller, %rdi

main_done:
    call puts

    mov $0, %rax
    leave
    ret

    .data
prompt: .string "enter a number: "
long_fmt: .string "%ld"
bigger: .string "bigger"
smaller: .string "smaller"
