#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid < 0) {
        perror("msgget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {

        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Child received: %s\n", message.msg_text);

        msgctl(msgid, IPC_RMID, NULL);
    }
    else {

        message.msg_type = 1;
        strcpy(message.msg_text, "Hello Message Queue");

        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Parent sent: %s\n", message.msg_text);

        wait(NULL); 
    }

    return 0;
}

