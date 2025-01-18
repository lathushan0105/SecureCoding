#include <stdio.h>
 
#define BUFSIZE 256
    
int read_file(const char *filename) {
    FILE* ptr = fopen(filename, "r");
    
    if (ptr == NULL) {
        printf("File cannot be opened.\n");
        return(-1);
    }
    
    char buff[BUFSIZE];
    
    while (fgets(buff, BUFSIZE, ptr) != NULL) {
        printf("%s", buff);
    }
        
    return 0; 
}

int main() {
    char filename[BUFSIZE];

    printf("Enter the name of the file to read: ");
    if (fgets(filename, BUFSIZE, stdin) != NULL) {
        // Remove the trailing newline character if present
        char *newline = strchr(filename, '\n');
        if (newline) {
            *newline = '\0';
        }
    }

    if (read_file(filename) == -1) {
        printf("Error reading the file.\n");
    }

    return 0;
}
