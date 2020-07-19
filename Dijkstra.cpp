#include<iostream>
#include"conio.h"

using namespace std;

class Dijkstra
{
	int n,cost[10][10],d[10],p[10],visited[10];
	
	public:
		
		void read_matrix();
		void shortpath(int);
		void display(int);		
};

void Dijkstra::read_matrix()
{
	int i,j;
	cout<<"Enter the number of vertices:";
	cin>>n;
	cout<<"Enter cost adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>cost[i][j];
		}
	}
}

void Dijkstra::shortpath(int src)
{
	int i,j,min,u,v;
	for(i=0;i<n;i++)
	{
		p[i]=src;
		visited[i]=0;
		d[i]=cost[src][i];
	}
	visited[src]=1;
	for(i=0;i<n;i++)
	{
		min=999;
		u=0;
		for(j=0;j<n;j++)
		{
			if(!visited[j])
			{
				if(d[j]<min)
				{
					min=d[j];
					u=j;
				}
			}
		}
		visited[u]=1;
		for(v=0;v<n;v++)
		{
			if(!visited[v] && ((d[u]+cost[u][v])<d[v]))
			{
				d[v]=d[u]+cost[u][v];
				p[v]=u;
			}
		}
	}
}
	
	void Dijkstra::display(int src)
	{
		int i,k,parent;
		for(i=0;i<n;i++)
		{
			if(i==src)
			{
				continue;
			}
			cout<<endl<<"The shortest path from "<<src<<" to "<<i<<" is ";
		    k=i;
		    cout<<k<<"<----";
		    while(p[k]!=src)
		    {
		    	cout<<p[k]<<"<---";
		    	k=p[k];
			}
			cout<<src;
			cout<<" and the cost is "<<d[i]<<endl;
		}
	}
	
	
	int main()
	{
		int source;
		Dijkstra d;
		d.read_matrix();
		cout<<endl<<"Enter the source:";
		cin>>source;
		d.shortpath(source);
		d.display(source);
		return 0;
	}
	
	

