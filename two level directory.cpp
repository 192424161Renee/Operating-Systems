#include <stdio.h>
#include <string.h>
int main(){
    char user[5][20], files[5][10][20];
    int fcount[5], u;
    printf("Enter number of users: ");
    scanf("%d",&u);
    for(int i=0;i<u;i++){
        printf("User %d name: ", i+1);
        scanf("%s", user[i]);
        printf("Number of files: ");
        scanf("%d",&fcount[i]);
        for(int j=0;j<fcount[i];j++){
            printf("File %d: ", j+1);
            scanf("%s", files[i][j]);
        }
    }
    char uname[20];
    printf("Search user: ");
    scanf("%s", uname);
    for(int i=0;i<u;i++){
        if(strcmp(uname,user[i])==0){
            printf("Files:\n");
            for(int j=0;j<fcount[i];j++)
                printf("%s\n", files[i][j]);
            return 0;
        }
    }
    printf("User not found\n");
}