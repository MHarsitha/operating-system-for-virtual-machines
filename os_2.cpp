#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int source, dest;
    char buffer[1024];
    int bytesRead;

    source = open("input.txt", O_RDONLY);   
    if (source < 0) {
        printf("Source file cannot be opened!\n");
        return 1;
    }

    dest = open("output.txt", O_WRONLY | O_CREAT, 0644);  
    if (dest < 0) {
        printf("Destination file cannot be opened!\n");
        return 1;
    }

    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead); 
    }

    close(source);
    close(dest);

    printf("File copied successfully.\n");

    return 0;
}

