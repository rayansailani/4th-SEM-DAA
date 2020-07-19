#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class BFS
{
    int n, a[10][10], s[10], source;

public:
    void read();
    void bfs();
    void print_data();
};
void BFS::read()
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
    cout << "Enter the source: " << endl;
    cin >> source;
}

void BFS::bfs()
{
    int u, v, f, r, s[10], q[10];
    f = r = 0;
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    q[r] = source;
    s[source] = 1;
    while (f <= r)
    {
        u = q[f++];
        for (v = 0; v <= n; v++)
        {
            if (a[u][v] == 1 && s[v] == 0)
            {
                s[v] = 1;
                q[++r] = v;
            }
        }
    }
}
void BFS::print_data()
{
    int i;
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
int main()
{
    BFS b;
    b.read();
    b.bfs();
    b.print_data();
}