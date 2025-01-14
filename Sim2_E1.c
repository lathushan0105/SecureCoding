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
    char cmd[BUFSIZE] = "wc -c < ";
    char filename[BUFSIZE];

    if (strlen(cmd) + strlen(argv[1]) < BUFSIZE){
        sscanf(argv[1], "%s", filename);
        strncat(cmd, filename, BUFSIZE);
        system(cmd);
    }
    
    return 0;
}
