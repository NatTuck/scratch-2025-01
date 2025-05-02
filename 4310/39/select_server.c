#define _GNU_SOURCE
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9090
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct conn_state {
    int fd;
    char buffer[BUFFER_SIZE];
} conn_state;

conn_state state[MAX_CLIENTS];

int
main(int argc, char* argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int opt = 1;

    for (int ii = 0; ii < MAX_CLIENTS; ++ii) {
        state[ii].fd = -1;
        memset(state[ii].buffer, 0, BUFFER_SIZE);
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(1);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("TCP Echo Server listening on port %d\n", PORT);

    fd_set fds;

    while (1) {
        FD_ZERO(&fds);
        FD_SET(server_fd, &fds);
        int max_fd = server_fd;

        for (int ii = 0; ii < MAX_CLIENTS; ++ii) {
            if (state[ii].fd != -1) {
                FD_SET(state[ii].fd, &fds);
                if (state[ii].fd > max_fd) {
                    max_fd = state[ii].fd;
                }
            }
        }

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int rv = select(max_fd + 1, &fds, 0, 0, &timeout);
        if (rv <= 0) {
            continue;
        }

        if (FD_ISSET(server_fd, &fds)) {
            accept_conn(server_fd);

            for (int ii = 0; ii < MAX_CLIENTS; ++ii) {
                if (FD_ISSET(state[ii].fd, &fds)) {
                    read_and_echo(state[ii].fd);
                }
            }
        }
    }
    // Accept incoming connection
    client_fd = accept4(server_fd,
        (struct sockaddr*)&client_addr,
        &client_len,
        SOCK_NONBLOCK);
    if (client_fd < 0) {
        if (errno == EWOULDBLOCK) {
            continue;
        }
        perror("Accept failed");
        continue;
    }

    printf("Connection accepted from %s:%d\n",
        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Echo back received data
    int bytes_read;
    while ((bytes_read = read(client_fd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received: %s", buffer);

        for (int ii = 0; buffer[ii]; ++ii) {
            if (buffer[ii] == 'e') {
                buffer[ii] = 'E';
            }
        }

        // Echo back
        write(client_fd, buffer, bytes_read);

        // If the message ends with a newline, we consider it a complete line
        if (buffer[bytes_read - 1] == '\n') {
            printf("Line echoed back\n");
        }
    }

    if (bytes_read < 0) {
        perror("Read error");
        exit(1);
    }

    printf("Connection closed\n");
    close(client_fd);
}

close(server_fd);
return 0;
}
