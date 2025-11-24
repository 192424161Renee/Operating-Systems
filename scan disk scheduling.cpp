#include <stdio.h>

int main() {
    int n, head, i, j, temp;
    int arr[50];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

   
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int pos = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] >= head) {
            pos = i;
            break;
        }
    }

    int total = 0;
    printf("\nSCAN Order: ");

  
    for (i = pos; i < n; i++) {
        printf("%d ", arr[i]);
        total += (i == pos ? arr[i] - head : arr[i] - arr[i - 1]);
    }

   
    total += (199 - arr[n - 1]);

  
    printf("199 ");
    for (i = pos - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
        total += (i == pos - 1 ? 199 - arr[pos - 1] : arr[i + 1] - arr[i]);
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
