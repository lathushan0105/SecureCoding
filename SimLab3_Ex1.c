#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char **argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Open the file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Failed to open the file");
        return -1;
    }

    // Redirect standard input
    if (dup2(fd, STDIN_FILENO) < 0) {
        perror("dup2 failed");
        close(fd);
        return -1;
    }

    close(fd);

    char *runCMD[3] = {"wc", "-c", NULL};
    execve("/usr/bin/wc", runCMD, NULL);
    
    // If execve fails
    perror("execve failed");
    return -1;
}
