#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file = fopen("/sys/kernel/debug/kmod_dir/kmod_file", "r+");
    if (file != NULL)  {
        char *path[BUFFER_SIZE];
        if (sscanf(argv[1], "%s", (char *) path)) {
            char *buffer[BUFFER_SIZE];
            fprintf(file, "path: %s", (char *) path);
            while (true) {
                char *result = fgets((char *) buffer, BUFFER_SIZE, file);
                if (feof(file))
                    break;
                printf("%s", result);
            }
        } else {
            printf("Wrong arguments. Try again.");
        }
        fclose(file);
    } else {
        printf("File is not found.");
    }
    
    return 0;
}


