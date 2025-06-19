// main.c
#include <stdio.h>
#include "coinfile.h"

int main() {
    char filename[128];
    printf("Enter file name: ");
    scanf("%127s", filename);

    int valid = ValidateFile(filename);
    if (valid == -1) {
        printf("Error: Could not open file %s\n", filename);
    } else if (valid) {
        printf("File is valid.\n");
    } else {
        printf("File has errors.\n");
    }
    return 0;
}
