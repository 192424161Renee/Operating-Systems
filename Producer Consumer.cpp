#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full, mutex;
int buffer = 0;

void* producer(void* arg) {
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer = 1;
    printf("Produced: %d\n", buffer);
    sem_post(&mutex);
    sem_post(&full);
    return NULL;
}

void* consumer(void* arg) {
    sem_wait(&full);
    sem_wait(&mutex);
    printf("Consumed: %d\n", buffer);
    buffer = 0;
    sem_post(&mutex);
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
