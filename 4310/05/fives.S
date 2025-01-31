    .global main
    .data
yup:    .string "yup, all fives"
nope:   .string "nope"

/*
int
all_match(char c, char* text)
{
  for (int ii = 0; text[ii] != 0; ++ii) {
    if (text[ii] != c) {
      return 0;
    }
  }
  return 1;
}

Variables:
    - c in %rdi
    - text in %rsi
    - ii in %rdx
    - text[ii] in %rcx
*/    
    .text
all_match:
    enter $0, $0

    mov $0, %rdx
am_for_cond:
    cmpb $0, (%rsi,%rdx,1)
    je am_for_done

    mov (%rsi,%rdx,1), %cl
    cmp %dil, %cl
    je am_for_inc

    mov $0, %rax
    jmp am_return
    
am_for_inc:
    inc %rdx
    jmp am_for_cond
    
am_for_done:
    mov $1, %rax

am_return:  
    leave
    ret

    
/*
int
main(int argc, char* argv[])
{
  // assume there is one command line argument

  if (all_match('5', argv[1])) {
    puts("yup, all fives");
  }
  else {
    puts("nope");
  }
        
  return 0;
}

Var mapping:

    - argc in %rdi
    - argv in %rsi
    - argv[1] also goes in %rsi
*/

main:
    enter $0, $0

    mov $1, %rax
    mov (%rsi, %rax, 8), %rsi  // function arg 2 for next call = argv[%rax = 1]

    leave
    ret
