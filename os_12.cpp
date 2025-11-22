#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
pthread_mutex_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;
    printf("Philosopher %d is thinking\n", id);
    sleep(1);
    pthread_mutex_lock(&forks[id]);
    pthread_mutex_lock(&forks[(id+1)%N]);
    printf("Philosopher %d is eating\n", id);
    sleep(1);
    pthread_mutex_unlock(&forks[id]);
    pthread_mutex_unlock(&forks[(id+1)%N]);
    printf("Philosopher %d finished eating\n", id);
    return NULL;
}

int main() {
    pthread_t ph[N];
    int ids[N];
    for(int i=0;i<N;i++) pthread_mutex_init(&forks[i],NULL);
    for(int i=0;i<N;i++) { ids[i]=i; pthread_create(&ph[i],NULL,philosopher,&ids[i]); }
    for(int i=0;i<N;i++) pthread_join(ph[i],NULL);
    return 0;
}

