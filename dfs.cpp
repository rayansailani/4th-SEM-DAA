#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class DFS
{
    int n, adj[10][10];

public:
    void read();
    void reach();
    void dfs(int u, int s[]);
    int connectivity();
};

void DFS::read()
{
    int i, j;
    cout << "Enter the number of elements in the adjacency matrix: " << endl;
    cin >> n;
    cout << "Enter the adjacency matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
}
void DFS::dfs(int u, int *s)
{
    int v;
    s[u] = 1;
    for (v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && s[v] == 0)
        {
            dfs(v, s);
        }
    }
}
void DFS::reach()
{
    int i, j, source;
    int s[10];
    for (i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    cout << "Enter the source: " << endl;
    cin >> source;
    dfs(source, s);
    for (i = 0; i < n; i++)
    {
        if (s[i] == 1)
        {
            cout << "Node " << i << " is reachable" << endl;
        }
        else
        {
            cout << "Node " << i << " is not reachable" << endl;
        }
    }
}
int DFS::connectivity()
{
    int i, j, s[10], flag;
    for (j - 0; j < n; j++)
    {

        for (i = 0; i < n; i++)
        {
            s[i] = 0;
        }
        dfs(j, s);
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return 1;
        }
        }
    return 0;
}
int main()
{
    DFS d;
    d.read();
    d.reach();
    int flag = d.connectivity();
    if (flag == 1)
    {
        cout << "The  graph is connected" << endl;
    }
    else
    {
        cout << "The  graph is not connected" << endl;
    }
}