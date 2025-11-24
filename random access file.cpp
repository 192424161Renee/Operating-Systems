#include <stdio.h>
typedef struct {
    int id;
    char name[20];
    float salary;
} Emp;
int main() {
    FILE *fp = fopen("emp.dat","wb+");
    Emp e[2]={{1,"John",5000},{2,"Mary",6000}};
    fwrite(e,sizeof(Emp),2,fp);
    int pos;
    printf("Enter record number (0/1): ");
    scanf("%d",&pos);
    fseek(fp, pos*sizeof(Emp), SEEK_SET);
    Emp x;
    fread(&x,sizeof(Emp),1,fp);
    printf("%d %s %.2f\n", x.id, x.name, x.salary);
    fclose(fp);
}