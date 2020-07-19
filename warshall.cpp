#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class warshall
{
    int n, a[10][10];

public:
    void read();
    void print_data();
    void path_matrix();
};

void warshall::read()
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
void warshall::print_data()
{
    int i, j;
    cout << "The path matrix is as follows: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void warshall::path_matrix()
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][k] == 1 && a[k][j] == 1)
                {
                    a[i][j] = 1;
                }
            }
        }
    }
}
int main()
{
    warshall w;
    w.read();
    w.path_matrix();
    w.print_data();
}