#include <stdio.h>

int main() {
    int disk[50] = {0}; 
    int diskSize = 20;
    int fileId = 1;
    int start, length;
    int i, rec;

    printf("Disk size (<=50): ");
    scanf("%d", &diskSize);

    
    printf("Enter starting block and length for file (start length): ");
    scanf("%d %d", &start, &length);
    if(start < 0 || start + length > diskSize) {
        printf("Invalid allocation range\n");
        return 0;
    }
    for(i = start; i < start + length; i++) disk[i] = fileId;

    printf("Disk allocation (index:content):\n");
    for(i=0;i<diskSize;i++) printf("%d:%d ", i, disk[i]);
    printf("\n");

    printf("Access record number (1..%d) of file: ", length);
    scanf("%d",&rec);
    if(rec >=1 && rec <= length) {
        printf("Record is at block %d\n", start + rec - 1);
    } else {
        printf("Invalid record number\n");
    }
    return 0;
}
