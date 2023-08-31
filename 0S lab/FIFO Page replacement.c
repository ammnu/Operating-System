#include <stdio.h>
int main()
{
    int i = 0, j = 0, k = 0, i1 = 0, m, n, rs[20], flag = 1, p[30];
    printf("FIFO page replacement algorithm\n");
    printf("Enter the number of frames:");
    scanf("%d", &n);
    printf("Your string should only contain exactly 20 numbers\n");
    printf("Enter the reference string:\n");
    while (i < 20) 
    {
        scanf("%d", &rs[i]);
        i++;
    }
    
    m = i;
    for (j = 0; j < n; j++)
        p[j] = -1;

    for (i = 0; i < m; i++)
    {
        printf("The number is %d",rs[i]);
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (p[j] == rs[i])
            {
                printf("  Data already in page...\n");
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            p[i1] = rs[i];
            i1++;
            k++;
            if (i1 == n)
                i1 = 0;

            for (j = 0; j < n; j++)
            {
                printf("\nPage %d: %d", j + 1, p[j]);
                if (p[j] == rs[i])
                    printf("*");
            }

            printf("\n\n");
        }
    }

    printf("Total number of page faults: %d", k);
    return 0;
}