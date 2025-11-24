#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t forks[5];
void* philosopher(void* num) {
    int id = *((int*)num);
    sem_wait(&forks[id]);
    sem_wait(&forks[(id+1)%5]);
    printf("Philosopher %d eating\n", id);
    sem_post(&forks[id]);
    sem_post(&forks[(id+1)%5]);
    return NULL;
}
int main() {
    pthread_t p[5];
    int ids[5] = {0,1,2,3,4};
    for(int i=0;i<5;i++) sem_init(&forks[i],0,1);
    for(int i=0;i<5;i++)
        pthread_create(&p[i], NULL, philosopher, &ids[i]);
    for(int i=0;i<5;i++)
        pthread_join(p[i], NULL);
    return 0;
}