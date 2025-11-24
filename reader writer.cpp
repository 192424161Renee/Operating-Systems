#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt;
pthread_mutex_t mutex;
int readcount = 0;
int data = 10;

void* reader(void* arg) {
    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader reads %d\n", data);

    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);

    return NULL;   
}

void* writer(void* arg) {
    sem_wait(&wrt);
    data += 5;
    printf("Writer writes %d\n", data);
    sem_post(&wrt);

    return NULL;   
}

int main() {
    pthread_t r1, r2, w;

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&w, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, NULL);

    pthread_join(r1, NULL);
    pthread_join(w, NULL);
    pthread_join(r2, NULL);

    return 0;
}
