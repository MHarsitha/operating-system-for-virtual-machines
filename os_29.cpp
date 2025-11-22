#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void *process() {
    pthread_mutex_lock(&lock);
    counter++;
    printf("Process in Critical Section. Counter = %d\n", counter);
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t t1, t2, t3;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, process, NULL);
    pthread_create(&t2, NULL, process, NULL);
    pthread_create(&t3, NULL, process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}

