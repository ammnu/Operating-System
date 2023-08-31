#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
    int choice, fd, sz;
    char c1[100];

    printf("IO System Calls in Linux\n");

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Create a file\n");
        printf("2. Open a file\n");
        printf("3. Close the file\n");
        printf("4. Write to the file\n");
        printf("5. Read from the file\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fd = creat("f1.txt", 0777);
                printf("File created with fd=%d\n", fd);
                close(fd);
                break;
            case 2:
                fd = open("f1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
                printf("File opened with fd=%d\n", fd);
                close(fd);
                break;
            case 3:
                close(fd);
                printf("File closed with fd=%d\n", fd);
                break;
            case 4:
                fd = open("f1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
                sz = write(fd, "hi,hello\n", strlen("hi,hello\n"));
                close(fd);
                printf("Data written to the file with fd=%d\n", fd);
                break;
            case 5:
                fd = open("f1.txt", O_RDONLY);
                sz = read(fd, c1, sizeof(c1) - 1);
                c1[sz] = '\0';
                printf("Size of character string sz=%d\n", sz);
                printf("File content: %s\n", c1);
                close(fd);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
