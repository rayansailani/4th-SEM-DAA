#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class topo
{
    int n, a[10][10], indegree[10];

public:
    void read();
    void find_indegree();
    void topo_sort();
};
void topo::read()
{
    int i, j;
    cout << "Enter the number of elements in the adjacency matrix: " << endl;
    cin >> n;
    cout << "Enter the adjacency matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}
void topo::find_indegree()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        int sum = 0;
        for (j = 0; j < n; j++)
        {
            sum = sum + a[j][i];
        }
        indegree[i] = sum;
    }
}
void topo::topo_sort()
{
    int i, j, k = 0;
    int u, v, t[10], s[10];
    int top = -1;
    find_indegree();
    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            s[++top] = i;
        }
    }
    while (top != -1)
    {
        u = s[top--];
        t[k++] = u;
        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    s[++top] = v;
                }
            }
        }
    }
    cout << "The topological ordering of the given graph is: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << t[i] + 1 << " ";
    }
    cout << endl;
}
int main()
{
    topo t;
    t.read();
    t.topo_sort();
}