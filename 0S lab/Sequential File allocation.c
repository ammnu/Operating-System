#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Fname[20];
    int start_block;
    int num_blocks;
} FileAllocation;

void createFile(FileAllocation files[], int* total_files) {
    if (*total_files >= 100) {
        printf("Maximum number of files reached.\n");
        return;
    }

    FileAllocation newFile;
    printf("Enter the filename: ");
    scanf("%s", newFile.Fname);
    printf("Enter the number of blocks required for the file: ");
    scanf("%d", &newFile.num_blocks);

    if (*total_files == 0) {
        newFile.start_block = 0;
    } else {
        FileAllocation lastFile = files[*total_files - 1];
        newFile.start_block = lastFile.start_block + lastFile.num_blocks;
    }

    files[*total_files] = newFile;
    (*total_files)++;

    printf("File '%s' created successfully.\n", newFile.Fname);
}

void displayFiles(FileAllocation files[], int total_files) {
    printf("\nFile Blocks Allocated:\n");
    for (int i = 0; i < total_files; i++) {
        printf("File: %s\t Start Block: %d\t Number of Blocks: %d\n",
            files[i].Fname, files[i].start_block, files[i].num_blocks);
    }
}

int main() {
    FileAllocation files[100];
    int total_files = 0;
    int choice;

    printf("Sequential File Allocation\n");

    do {
        printf("\nMenu:\n");
        printf("1. Create a file\n");
        printf("2. Display allocated file blocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(files, &total_files);
                break;
            case 2:
                displayFiles(files, total_files);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
