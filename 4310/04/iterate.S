    .global iterate

/*
long
iterate(long x)
{
    if (x % 2 == 0) {
        return x / 2;
    }
    else {
        return 3 * x + 1;
    }
}

Variable mappings:
 - x: %rdi

*/

iterate:
    // prologue
    enter $0, $0
    
    // body

    // if (x % 2 == 0) {
    mov $2, %rsi
    mov $0, %rdx
    mov %rdi, %rax
    idiv %rsi

    mov $0, %rsi
    cmp %rdx, %rsi
    je then_case
    jmp else_case
then_case:

    // return x / 2;
    mov $2, %rsi
    mov $0, %rdx
    mov %rdi, %rax
    idiv %rsi

    jmp if_done
else_case:

    mov $3, %rax
    imul %rdi
    add $1, %rax

if_done:

    // epilogue
    leave
    ret


/*
int
main(int argc, char* argv[])
{
    long x = atol(argv[1]);
    long i = 0;
    
    while (x > 1) {
        printf("%ld\n", x);
        x = iterate(x);
        i++;
    }

    printf("i = %ld\n", i);
    return 0;
}
*/
