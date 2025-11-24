#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[200], word[50];

    
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Could not open data.txt\n");
        return 0;
    }

   
    printf("Enter word to search: ");
    scanf("%s", word);

    printf("\nLines containing '%s':\n", word);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, word) != NULL) {  // similar to grep
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
