
#include <arpa/inet.h>
#include <assert.h>
#include <bsd/string.h> // sudo apt install libbsd-dev
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "aok.h"

typedef struct header {
    uint16_t len;
    uint8_t type;
    uint16_t blen;
} header;

typedef struct login_msg {
    header hdr;
    char user[16];
    char pass[16];
} login_msg;

int
main(int argc, char* argv[])
{
    struct sockaddr_in addr;
    int rv;

    const char* host = "107.175.221.132";
    const int port = 9001;

    printf("Connecting to %s:%d\n", host, port);

    addr.sin_family = AF_INET;
    rv = inet_pton(AF_INET, host, &(addr.sin_addr));
    assert(rv == 1);
    addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    aok(sock);

    rv = connect(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));
    aok(rv);

    login_msg login;
    login.hdr.len = sizeof(login);
    login.hdr.type = 1;
    login.hdr.blen = sizeof(login_msg);
    strlcpy(login.user, "frank", 16);
    strlcpy(login.pass, "letmein", 16);

    send(sock, &login, sizeof(login), 0);

    login_msg resp;
    recv(sock, &resp, sizeof(resp), 0);

    printf("Got hello: %s\n", resp.user);

    rv = close(sock);
    aok(rv);
    return 0;
}
