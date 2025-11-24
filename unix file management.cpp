#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[100];

  
    fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 0;
    }

    fprintf(fp, "Hello, this is a file management simulation.\n");
    fclose(fp);

    
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    printf("File Content:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}
