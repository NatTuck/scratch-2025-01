
## Command Line Shell

Process for implementing operators.

### Redirect

The plan:

- Start in parent process.
- Figure out that we're doing a redirect.
- Fork, in child:
  - Do the redirect, by setting the appropriate file descriptor
    to point to the correct file.
  - For example, for redirect out (cmd > file) we need to open
    the file and then set fd 1 to be that file.
  - Exec the command.
- In parent, wait for child to finish.

### Pipe

The problem:

- To programs running.
- stdout for the first program needs to be stdin for the second.
- No files are involved.
- "foo | bar" means stdout for foo is stdin for bar.

The plan (for "foo | bar"):

- We need to run two new processes, one for foo and one for bar.
- The shell process doesn't need either end of the pipe.
- Step 1: Fork before creating the pipe, creating child 1.
  - In child 1:
  - Create the pipe.
  - Fork, creating child 2.
  - In child 1 (will become bar):
    - Close the write end of the pipe.
    - Set the read end of the pipe to be stdin.
    - Exec bar
  - In child 2 (will become foo):
    - Close the read end of the pipe.
    - Set the write end of the pipe to be stdout.
    - Exec foo
- In the shell process, wait for child 1 (bar).

## Background

Plan for a normal command:

 - Fork
 - Exec command in the child
 - Wait for our child

Plan for a background command:

 - Fork
 - Exec command in the child
 - Don't wait.

## Semicolon (e.g. "foo; bar")

Plan:

 - Run the first command (fork, exec, wait)
 - Run the second command (fork, exec, wait)

## Logical operators (foo && bar, foo || bar)

- Next time: See how to get exit code from wait(2)




 
