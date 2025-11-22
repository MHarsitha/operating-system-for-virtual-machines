#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    write(fd, "Operating Systems", 18);

    // fcntl
    int flags = fcntl(fd, F_GETFL);
    printf("File flags: %d\n", flags);

    // lseek
    lseek(fd, 0, SEEK_SET);

    // stat
    struct stat s;
    stat("sample.txt", &s);
    printf("File size: %ld bytes\n", s.st_size);

    // list directory
    DIR *d = opendir(".");
    struct dirent *dir;
    printf("\nDirectory listing:\n");
    while((dir = readdir(d)) != NULL)
        printf("%s\n", dir->d_name);

    closedir(d);
    close(fd);
}

