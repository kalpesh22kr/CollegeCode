#include <iostream>
#include <stdlib.h>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front, rear, v, visit[10], visited[10];
int stk[10], top, visit1[10], visited1[10];

int main()
{
    int m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;

    cout << "\nEDGES :(u,v)\n";
    for (k = 1; k <= m; k++)
    {
        cout << "\nu:";
        cin >> i;
        cout << "v:";
        cin >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }

    cout << "The adjacency matrix of the graph is:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }

    cout << "Enter initial vertex for BFS: ";
    cin >> v;
    // Perform BFS
    cout << "The BFS of the Graph is:\n";
    front = rear = 0;
    qu[rear++] = v;
    visited[v] = 1;

    while (front < rear)
    {
        v = qu[front++];
        cout << v << " ";

        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] != 0 && visited[j] == 0)
            {
                qu[rear++] = j;
                visited[j] = 1;
            }
        }
    }
    cout << endl;

    cout << "Enter initial vertex for DFS: ";
    cin >> v;

    // Perform DFS
    cout << "The DFS of the Graph is:\n";
    top = 0;
    stk[top] = v;
    visited1[v] = 1;
    k = 1;

    cout << v << " ";
    while (top >= 0)
    {
        v = stk[top];
        int flag = 0;
        for (j = 1; j <= n; j++)
        {
            if (cost[v][j] != 0 && visited1[j] == 0)
            {
                cout << j << " ";
                visited1[j] = 1;
                stk[++top] = j;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            top--;
    }

    return 0;
}