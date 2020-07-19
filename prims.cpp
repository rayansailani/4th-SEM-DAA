#include <iostream>
#include <conio.h>
using namespace std;
class Prims
{
    int n, a[10][10];

public:
    void read_data();
    void min();
};

void Prims::read_data()
{
    int i, j;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the cost matrix" << endl
         << "0-self loop  999-no edge" << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
}

void Prims::min()
{
    int min = 999;
    int source = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0 && a[i][j] <= min)
            {
                min = a[i][j];
                source = i;
            }
        }
    int d[10], s[10], p[10];
    for (int i = 0; i < n; i++)
    {
        d[i] = a[source][i];
        s[i] = 0;
        p[i] = source;
    }
    s[source] = 1; /// s = {0, 1, 1} /// d = {20, 5, 999} // p = {1, 2 ,2}
    int sum = 0;
    int k = 0;

    int t[10][2];
    for (int i = 1; i < n; i++)
    {
        min = 999;
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 0)
            {
                if (d[j] <= min)
                {
                    min = d[j]; //min = 20
                    u = j;      //u = 0
                }
            }
        }
        // min = 5, u = 1

        t[k][0] = u;
        t[k][1] = p[u];
        k++;
        sum += a[p[u]][u]; //// sum = 5+20
        s[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (s[v] == 0 && a[u][v] < d[v])
            {
                d[v] = a[u][v]; /// d = {20 ,5 ,999}
                p[v] = u;       /// p = {1, 2 ,2}
            }
        }
    }

    cout << "Spanning tree exist and minimum spanning tree is" << endl;
    for (int i = 0; i < n - 1; i++)
        cout << t[i][0] << " " << t[i][1] << endl;
    cout << "the cost of the spanning tree= " << sum;
}

int main()
{
    Prims p;

    p.read_data();
    p.min();
}
