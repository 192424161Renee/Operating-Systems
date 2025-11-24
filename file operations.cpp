#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

   
    fp = fopen("filedemo.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        return 0;
    }
    fprintf(fp, "This is a simple file management demo.");
    fclose(fp);

    
    fp = fopen("filedemo.txt", "r");
    if (fp == NULL) {
        printf("Error reading file\n");
        return 0;
    }

    printf("File Content:\n");
    while (fgets(text, sizeof(text), fp) != NULL) {
        printf("%s", text);
    }
    fclose(fp);

   
    if (remove("filedemo.txt") == 0)
        printf("\n\nFile deleted successfully.\n");
    else
        printf("\n\nError deleting file.\n");

    return 0;
}
