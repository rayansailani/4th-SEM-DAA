#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class floyds
{
    int n, c[10][10];

public:
    void read();
    void print_data();
    void cost_matrix();
};
int min(int a, int b)
{
    return a > b ? b : a;
}

void floyds::read()
{
    int i, j;
    cout << "Enter the number of elements in the cost matrix: " << endl;
    cin >> n;
    cout << "Enter the cost matrix: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
}
void floyds::print_data()
{
    int i, j;
    cout << "The cost matrix is as follows: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
void floyds::cost_matrix()
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
}
int main()
{
    floyds f;
    f.read();
    f.cost_matrix();
    f.print_data();
}