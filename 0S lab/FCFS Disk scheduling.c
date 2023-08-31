#include <stdio.h>
#include <stdlib.h>

int main() {
    int tracks[20], n, i, headMovements[20], total = 0, start, prev, curr, maxSeekTime = 0;
    float averageHeadMovements;
    printf("FCFS Disk Scheduling \n");
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the starting position: ");
    scanf("%d", &start);

    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }

    prev = start;
    for (i = 0; i < n; i++) {
        curr = tracks[i];
        headMovements[i] = abs(curr - prev);
        total += headMovements[i];
        if (headMovements[i] > maxSeekTime) {
            maxSeekTime = headMovements[i];
        }
        prev = curr;
    }

    averageHeadMovements = (float)total / n;

    printf("\nTracks traversed\tDifference between tracks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t\t%d\n", tracks[i], headMovements[i]);
    }

    printf("\nAverage header movements: %f\n", averageHeadMovements);
    printf("Maximum seek time: %d\n", maxSeekTime);

    return 0;
}
