#include <stdio.h>
#include <dirent.h>

int main() {
    FILE *fp;
    char ch;

   
    fp = fopen("demo.txt", "w+");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    fprintf(fp, "ABCDE12345");
    fflush(fp);

   
    fseek(fp, 5, SEEK_SET); 
    printf("File pointer moved to position 5.\n");

   
    ch = fgetc(fp);
    printf("Character at position 5: %c\n", ch);

    fclose(fp);

   
    printf("\nListing files in current directory:\n");

    DIR *d;
    struct dirent *dir;
    d = opendir(".");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        printf("Could not open directory.\n");
    }

    return 0;
}
