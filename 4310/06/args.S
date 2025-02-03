/*
int
main(int argc, char** argv)
{
    char* arg;
    while (arg = *(argv++)) {
        puts(arg);
    }
    return 0;
}

Variable mapping:
  - argv : r12
  - arg  : r13
*/



    .global main
    .text
main:
    push %r12
    push %r13
    enter $0, $0 

    mov %rsi, %r12 // argv

top_of_the_loop:
    // *(r12)
    mov (%r12), %r13

    cmp $0, %r13
    jz end_of_the_function

    mov %r13, %rdi
    call puts
    
    add $8, %r12
    jmp top_of_the_loop

end_of_the_function:
    leave
    pop %r13
    pop %r12
    ret
