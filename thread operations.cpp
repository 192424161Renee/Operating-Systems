#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Thread is running...\n");
    pthread_exit(NULL); 
}

int main() {
    pthread_t t1;
    int result;

   
    result = pthread_create(&t1, NULL, threadFunction, NULL);
    if (result != 0) {
        printf("Thread creation failed\n");
        return 0;
    }

   
    if (pthread_equal(t1, t1))
        printf("Thread IDs are equal.\n");
    else
        printf("Thread IDs are not equal.\n");

   
    pthread_join(t1, NULL);

    printf("Thread has finished execution.\n");
    return 0;
}
