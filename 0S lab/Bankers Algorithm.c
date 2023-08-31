#include <stdio.h>
#include <stdbool.h>

int main() 
{
    int available[10], max[10][10], allocation[10][10];
    int need[10][10], running[10];
    int n, m, i, j, exec, count = 0;

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
    //printMatrix(allocation[n][m],n,m);
    printf("Enter the available resources:\n");
    
    for (i = 0; i < m; i++) 
    {
        scanf("%d", &available[i]);
    }
    //printMatrix(available[1][m],1,m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("The need matrix \n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++) {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    //printMatrix(need[n][m],n,m);
    // Initialize all processes as running
    for (i = 0; i < n; i++) 
    {
        running[i] = 1;
        count++;
    }

    // Check for safe state
    printf("\nSafe sequence: ");
    while (count != 0) {
        bool safe = false;
        for (i = 0; i < n; i++) {
            if (running[i]) 
            {
                bool can_run = true;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j]) 
                    {
                        can_run = false;
                        break;
                    }
                }

                if (can_run) 
                {
                    printf("%d ", i);
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

        if (!safe) {
            printf("\nSystem is in an unsafe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\n");
    return 0;
}
