#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct sockaddr_in addr;
    int rv;

    const char* host = "142.250.65.238";
    const int port = 80;

    addr.sin_family = AF_INET;
    rv = inet_pton(AF_INET, host, &(addr.sin_addr));
    assert(rv == 1);
    addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock >= 0);

    rv = connect(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
    if (rv != 0) {
        perror("connect");
        return 1;
    }

    const char* msg = "GET / HTTP/1.0\r\n\r\n";
    rv = send(sock, msg, strlen(msg), 0);
    assert(rv >= 0);

    char buff[1280];
    int count = recv(sock, buff, 1279, 0);
    assert(count >= 0);

    buff[1279] = 0;

    printf("%s\n", buff);

    close(sock);
    return 0;
}
