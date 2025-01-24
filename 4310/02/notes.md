

# Operating Systems: Lecture 2

 - On Unix-type systems, we access system calls primarly from the C language.
 - The mechanism of making system calls is a machine instruction, and if we want
   to explicitly execute that instruciton, we need assembly code.
 - We can conceputally think of C as something that's going to be translated
   to assembly code, kind of 1 for 1.
  
To run a C program (conceptually)

 - First we compile the C program to assembly.
 - Then we assemble the assembly into object files (chunks of machine code / binary).
 - Then we link the object files together into an executable (a complete program in machine code / binary).

