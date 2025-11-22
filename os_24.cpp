#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char writeData[] = "Hello OS Lab";
    char readData[50];

    fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    write(fd, writeData, sizeof(writeData));
    lseek(fd, 0, SEEK_SET);
    read(fd, readData, sizeof(writeData));
    close(fd);

    printf("File Content: %s\n", readData);
}

