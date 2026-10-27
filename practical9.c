#include <stdio.h>

#define MAX 20
#define INF 99999

int main()
{
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int n, i, j, edges = 0;
    int min, a = 0, b = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == INF)
        {
            printf("Graph is disconnected. MST cannot be formed.\n");
            return 0;
        }

        printf("%d - %d : %d\n", a + 1, b + 1, min);

        totalCost += min;
        visited[b] = 1;
        edges++;
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
