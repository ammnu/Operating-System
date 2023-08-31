#include <stdio.h>
#include <stdbool.h>

int main() {
    int available[10], max[10][10], allocation[10][10];
    int need[10][10], running[10];
    bool deadlockDetected = false; // New variable to track deadlock detection
    int n, m, i, j, count = 0;

    printf("Deadlock detection Algorithm\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize all processes as running
    for (i = 0; i < n; i++) {
        running[i] = 1;
        count++;
    }

    // Check for safe state
    while (count != 0) {
        bool safe = false;
        for (i = 0; i < n; i++) {
            if (running[i]) {
                bool can_run = true;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        can_run = false;
                        break;
                    }
                }

                if (can_run) {
                    running[i] = 0;
                    count--;
                    safe = true;

                    // Release resources after execution
                    for (j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    break;
                }
            }
        }

        // If no process can run, deadlock is detected
        if (!safe) {
            deadlockDetected = true;
            break;
        }
    }

    // Print the result based on deadlock detection
    if (deadlockDetected) {
        printf("\nDeadlock detected and therefore the system is in an unsafe state.\n");
        printf("The deadlocked processes are: ");
        for (i = 0; i < n; i++) {
            if (running[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("\nSystem is in a safe state.\n");
    }

    return 0;
}
