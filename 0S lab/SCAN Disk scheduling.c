#include <stdio.h>
#include <stdlib.h>

int main() {
    int tracks[20], n, i, headMovements[20], total = 0, start, curr;
    int maxSeekTime = 0;
    float averageHeadMovements;
    printf("SCAN Disk Scheduling\n");
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the starting position: ");
    scanf("%d", &start);

    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    // Add the starting position to the tracks array
    tracks[n] = start;
    n++; // Increase the number of tracks

    // Sort the tracks array in ascending order
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) 
            {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the position of the starting track
    for (i = 0; i < n; i++) {
        if (tracks[i] == start) {
            break;
        }
    }

    // Traverse the tracks in the forward direction
    int index = i; // Start position in the sorted array
    for (i = index; i < n - 1; i++) {
        curr = tracks[i + 1];
        headMovements[i] = curr - tracks[i];
        total += headMovements[i];
        if (headMovements[i] > maxSeekTime) {
            maxSeekTime = headMovements[i];
        }
    }

    // Traverse the tracks in the reverse direction
    for (i = index - 1; i >= 0; i--) {
        curr = tracks[i];
        headMovements[i] = tracks[i + 1] - curr;
        total += headMovements[i];
        if (headMovements[i] > maxSeekTime) {
            maxSeekTime = headMovements[i];
        }
    }

    averageHeadMovements = (float)total / (n - 1);

    printf("\nTracks traversed\tDifference between tracks\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d\t\t\t%d\n", tracks[i], headMovements[i]);
    }

    printf("\nAverage header movements: %f\n", averageHeadMovements);
    printf("Maximum seek time: %d\n", maxSeekTime);

    return 0;
}
