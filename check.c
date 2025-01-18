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
    if (read_file("Hello.txt") == -1) {
        printf("Error reading the file.\n");
    }

    return 0;
}
