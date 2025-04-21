#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void aok1(int rv, int line)
{
    if (rv < 0) {
        printf("At line %d\n", line);
        perror("aok");
        exit(1);
    }
}

#define aok(rv) aok1(rv, __LINE__)

int main(int argc, char* argv[])
{
    int cpid;
    int fds[2];

    int rv = pipe(fds);
    aok(rv);

    int p_read = fds[0];
    int p_write = fds[1];

    if ((cpid = fork())) {
        rv = close(p_read);
        aok(rv);
        // set p_write is stdout.
        rv = close(1);
        aok(rv);
        rv = dup2(p_write, 1);
        aok(rv);
        rv = close(p_write);
        aok(rv);

        // parent
        char* text = "one\ntwo\nthree\nfour";
        write(1, text, strlen(text));
        close(1); // so that the pipe / sort command gets EOF

    } else {
        rv = close(p_write);
        aok(rv);
        aok(close(0));
        aok(dup(p_read)); // copies to lowest fd, can't be lower than 0
        aok(close(p_read));

        printf("In child, pid = %d\n", getpid());

        char* args[] = { "sort", 0 };
        rv = execvp("sort", args);
        aok(rv);

        // we never get here, so the child
        // doesn't execute the rest of main
    }

    rv = waitpid(cpid, 0, 0);
    aok(rv);

    return 0;
}
