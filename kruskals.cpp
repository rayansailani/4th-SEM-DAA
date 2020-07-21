#include <iostream>
using namespace std;

int find(int v, int p[])
{
    while (p[v] != v)
    {
        v = p[v];
    }
    return v;
}

void union_ig(int i, int j, int p[])
{
    if (i < j)
        p[j] = i;
    else
        p[i] = j;
}

void kruskal(int n, int c[10][10])
{
    int count, i, p[10], min, j, u, v, k, t[10][2], sum;
    count = 0;
    k = 0;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        p[i] = i;
    }
    while (count < n)
    {
        /* code */
        min = 999;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (c[i][j] < min)
                {
                    min = c[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (min == 999)
            break;
        i = find(u, p);
        j = find(v, p);
        if (i != j)
        {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += min;
            union_ig(i, j, p);
        }
        c[u][v] = c[v][u] = 999;
    }
    if (count == n - 1)
    {
        cout << "cost of spanning tree: " << sum << endl;
        cout << "spanning tree is shown below" << endl;
        for (k = 0; k < n - 1; k++)
        {
            cout << t[k][0] << " - " << t[k][1] << endl;
        }
    }
}

int main()
{
    int n, i, j, u, m, c[10][10];
    int v;
    int h;
    cout << "enter no of nodes" << endl;
    cin >> n;
    cout << "enter the no of edges" << endl;
    cin >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 999;
        }
    }
    for (i = 0; i < m; i++)
    {
        cout << "enter the next edges" << endl;
        cin >> u >> v;
        cout << "enter the cost" << endl;
        cin >> h;
        c[v][u] = c[u][v] = h;
    }
    kruskal(n, c);
    return 0;
}