#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
class tsp
{
    int n, a[10][10], v[10];

public:
    int cost;
    void read_matrix();
    void mincost(int);
    int least(int);
    tsp()
    {
        cost = 0;
    }
};
void tsp::read_matrix()
{
    int i, j;
    cout << "Enter the number of  nodes: " << endl;
    cin >> n;
    cout << "Enter the cost matrix: " << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
            v[i] = 0;
        }
}
int tsp::least(int c)
{
    int i, nc = 999, min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if (a[c][i] != 0 && v[i] == 0)
            if (a[c][i] + a[i][c] <= min)
            {
                min = a[i][0] + a[c][i];
                nc = i;
                kmin = a[c][i];
            }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}
void tsp::mincost(int city)
{
    int i, ncity;
    v[city] = 1;
    cout << city + 1 << setw(5);
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}
int main()
{
    int i, j, source;
    tsp t;
    t.read_matrix();
    cout << "Enter the source city: " << endl;
    cin >> source;
    cout << "Sequence of cities visited: " << endl;
    t.mincost(source);
    cout << endl
         << "The minimum cost is: " << t.cost << endl;
}
