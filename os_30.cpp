#include <stdio.h>
#include <pthread.h>

void *fun() {
    printf("Thread Running\n");
    pthread_exit(NULL);   // exit
}

int main() {
    pthread_t t1, t2;

    // create
    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);

    // equal
    if (pthread_equal(t1, t2))
        printf("Both threads are same\n");
    else
        printf("Threads are different\n");

    // join
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread completed.\n");
    return 0;
}

