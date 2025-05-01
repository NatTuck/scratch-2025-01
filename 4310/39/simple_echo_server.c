#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9090
#define BUFFER_SIZE 1024

int
main(int argc, char* argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int opt = 1;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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

    while (1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len)) < 0) {
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
