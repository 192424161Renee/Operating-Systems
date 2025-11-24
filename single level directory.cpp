#include <stdio.h>
#include <string.h>
int main() {
    char dir[10][20];
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter file %d: ", i+1);
        scanf("%s", dir[i]);
    }
    char name[20];
    printf("Search file: ");
    scanf("%s", name);
    int found=0;
    for(int i=0;i<n;i++){
        if(strcmp(dir[i], name)==0){ found=1; break; }
    }
    printf(found ? "File Found\n":"File Not Found\n");
    return 0;
}