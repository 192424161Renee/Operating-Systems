#include <stdio.h>

int buffer = 0;      // number of items in buffer
int maxSize = 5;     // buffer capacity

void produce() {
    if (buffer == maxSize) {
        printf("Buffer is full! Producer cannot add.\n");
    } else {
        buffer++;
        printf("Producer produced an item. Buffer = %d\n", buffer);
    }
}

void consume() {
    if (buffer == 0) {
        printf("Buffer is empty! Consumer cannot remove.\n");
    } else {
        buffer--;
        printf("Consumer consumed an item. Buffer = %d\n", buffer);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            produce();
        else if (choice == 2)
            consume();
        else if (choice == 3)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}
