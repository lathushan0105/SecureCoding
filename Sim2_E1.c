#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    
    char *runCMD[4] = {"wc", "-c"};

    if (strlen(runCMD[0]) + strlen(runCMD[1]) + strlen(argv[1]) < BUFSIZE){
        runCMD[2] = argv[1];
        runCMD[3] = NULL;
        execve("/usr/bin/wc", runCMD, NULL);
        perror("execve failed");
    }
    
    return 0;
}
