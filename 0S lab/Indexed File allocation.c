#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Fname[20];
    int index_block;
} IndexEntry;

typedef struct {
    char data[512]; // Data block for file content (512 bytes in this example)
} DataBlock;

void createFile(IndexEntry indexTable[], int* total_files, int* total_index_entries) {
    if (*total_files >= 100) {
        printf("Maximum number of files reached.\n");
        return;
    }

    if (*total_index_entries >= 512) {
        printf("Disk space for index table is full.\n");
        return;
    }

    IndexEntry newIndexEntry;
    printf("Enter the filename: ");
    scanf("%s", newIndexEntry.Fname);

    newIndexEntry.index_block = *total_index_entries;
    indexTable[*total_index_entries] = newIndexEntry;

    (*total_files)++;
    (*total_index_entries)++;

    printf("File '%s' created successfully.\n", newIndexEntry.Fname);
}

void displayFiles(IndexEntry indexTable[], int total_files) {
    printf("\nFile Blocks Allocated:\n");
    for (int i = 0; i < total_files; i++) {
        printf("File: %s\t Index Block: %d\n",
            indexTable[i].Fname, indexTable[i].index_block);
    }
}

int main() 
{
    IndexEntry indexTable[512];
    int total_files = 0;
    int total_index_entries = 0;
    int choice;

    printf("Indexed File Allocation\n");

    do {
        printf("\nMenu:\n");
        printf("1. Create a file\n");
        printf("2. Display allocated file blocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(indexTable, &total_files, &total_index_entries);
                break;
            case 2:
                displayFiles(indexTable, total_files);
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
