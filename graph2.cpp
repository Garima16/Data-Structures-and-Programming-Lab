#include<bits/stdc++.h>
#define FOR(i,z) for(int i=0;i<z;i++)
using namespace std;


int mat[10][10];
void has_cycle(int *pred,bool *visited,int n)
//for visited vertex i, if there is any adjacent vertex j of i which is visited and 
// if j is not its parent,then graph contains cycle
{
	for(int i=1;i<n;i++)
	{	
		if(visited[i])
		{
			FOR(j,n)
			{
				int a=mat[i][j];
				if(a && visited[j] && pred[i]!=j)
				{
					cout<<"\ngraph contains cycle\n";
					return ;
				}
			}	
		}			
	}
	cout<<"\ngraph does not contain cycle\n";
}

void dfs(int s,int n)
{
	cout<<"DFS\n";
	stack<int>stack;
	stack.push(s);
	bool visited[n];
	int pred[n];
	for(int a=0;a<n;a++)
	{
		visited[a]=0;
		pred[a]=0;
	}
	pred[s]=0;	
	while(!stack.empty())
	{
		int t=stack.top();
		stack.pop();
		if(!visited[t])
		{
			cout<<t<<" ";
			visited[t]=1;
			/*
			int flag=0;
			if(!flag)
				flag=has_cycle(pred,visited,t,n);// t is now visited, check if graph contains cycle
			*/
			FOR(i,n)
			{
				if(mat[t][i] && !visited[i]) //check adjacent vertices of vertex t
				{
					stack.push(i);
					pred[i]=t;
				}
			}
		}
	}
	int flag=0;
	FOR(i,n)
	{
		if(!visited[i])
		{
			cout<<"\ngraph has disconnected components\n";
			flag=1;
			break;
		}
	}
	if(!flag)
		cout<<"\ngraph doesnot have disconnected components\n";
	has_cycle(pred,visited,n);
}

void print(int n)
{
	FOR(i,n)
	{
		cout<<"Adjacent vertices of "<<i<<":";
		for(int j=0;j<n;j++)
		{
			if(mat[i][j])
				cout<<j<<" ";
		}
	cout<<"\n";
	}
	
}

int main()
{
	int n;
	cout<<"Enter number of vertices\n";
	cin>>n;

	FOR(i,n-1)
	{
		cout<<"adjacent vertices of "<<i<<"\n";
		int j=i+1;
		for(j;j<n;j++)
		{			
			cin>>mat[i][j];
			mat[i][i]=0;
			mat[j][i]=mat[i][j];
		}
	}
	print(n);	
	dfs(0,n);//0 is the source vertex
	return 1;
}