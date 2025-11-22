#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    int segment_id;
    char *shared_memory;

    segment_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (segment_id < 0) {
        perror("shmget failed");
        exit(1);
    }

    shared_memory = (char*) shmat(segment_id, NULL, 0);
    if (shared_memory == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
   
        sleep(1); 
        printf("Child reads: %s\n", shared_memory);

        shmdt(shared_memory);
        shmctl(segment_id, IPC_RMID, NULL);
    } 
    else {
        
        strcpy(shared_memory, "Hello Shared Memory");
        printf("Parent writes: %s\n", shared_memory);
        wait(NULL); 
    }

    return 0;
}

