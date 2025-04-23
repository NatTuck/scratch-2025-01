#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int cpid;
    if ((cpid = fork())) {
        // parent
        printf("Spawned child %d, waiting...\n", cpid);
        int status = 0;
        int wpid = wait(&status);
        printf("Child %d terminated with status %d\n", wpid, status);
        // read: man wait(2)
    } else {
        char* args[] = { "./ret", "11", 0 };
        printf("Running ./ret 11....\n");
        execvp("./ret", args);
    }

    return 0;
}
