#include <stdio.h>
#include <pthread.h>
void* runThread(void* arg) {
    int id = *((int*)arg);
    printf("Thread %d running\n", id);
    return NULL;
}
int main() {
    pthread_t t[3];
    int id[3] = {1,2,3};

    for(int i=0;i<3;i++)
        pthread_create(&t[i], NULL, runThread, &id[i]);

    for(int i=0;i<3;i++)
        pthread_join(t[i], NULL);

    return 0;
}
