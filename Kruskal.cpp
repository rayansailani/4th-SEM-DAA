#include <iostream>
#include <conio.h>

using namespace std;

class Kruskal
{
	int c[10][10], n, m;

public:
	void get_data();
	int find(int, int[]);
	void union_ij(int, int, int[]);
	void kruskal();
};

void Kruskal::get_data()
{
	int u, v;
	cout << "Enter the number of nodes:";
	cin >> n;
	cout << "Enter the number of edges:";
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = 999;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << "Enter an edge and it's cost:" << endl;
		cin >> u >> v;
		cin >> c[u][v];
		c[v][u] = c[u][v];
	}
}

int Kruskal::find(int v, int p[])
{
	while (p[v] != v)
	{
		v = p[v];
	}
	return v;
}

void Kruskal::union_ij(int i, int j, int p[])
{
	if (i < j)
	{
		p[j] = i;
	}
	else
	{
		p[i] = j;
	}
}

void Kruskal::kruskal()
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
		{
			break;
		}
		i = find(u, p);
		j = find(v, p);
		if (i != j)
		{
			t[k][0] = u;
			t[k][1] = v;
			k += 1;
			count += 1;
			sum += min;
			union_ij(i, j, p);
		}
		c[v][u] = c[u][v] = 999;
	}
	if (count == n - 1)
	{
		cout << "Cost of spanning tree=" << sum << endl;
		cout << "Spanning tree is shown below" << endl;
		for (k = 0; k < n - 1; k++)
		{
			cout << t[k][0] << "," << t[k][1] << endl;
		}
		return;
	}
	cout << "Spanning tree doesn't exist" << endl;
}

int main()
{
	Kruskal k;
	k.get_data();
	k.kruskal();
	return 0;
}
