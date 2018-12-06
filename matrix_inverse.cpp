#include<iostream>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void print(int n,float mat[][20])
{
	FOR(i,n)
	{
		FOR(j,n)
		{
			cout<<mat[i][j]<<" ";	
		}
		cout<<"\n";
	}	
}

void interchange(int m,int n,float mat[][20],int i)
{
	float temp[n];
	int index;
	for(int a=i+1;a<m;a++)
	{
		if(mat[a][i])
			{
				index=a;
				break;
			}
	}
	FOR(j,n)
	{
		temp[j]=mat[i][j];
		mat[i][j]=mat[index][j];
	}
	FOR(j,n)
		mat[index][j]=temp[j];
}

int determinant(int n,float mat[][20])
{
	FOR(i,n)
	{
		FOR(j,n)
		{
			if(j>i)
			{
				if(!mat[i][i])
				{
					interchange(n,n,mat,i);	
					//print(n,mat);	
				}				
				float ratio=mat[j][i]/mat[i][i];
				FOR(k,n)
				{
					mat[j][k]-=ratio*mat[i][k];
				}				
			}			
		}
	}
	float det=mat[0][0];
	for(int l=1;l<n;l++)
	{
		det*=mat[l][l];
	}
	return det;
}
	
void inverse(int n,float mat[][20])
{
	FOR(i,n)
	{
		for(int j=n;j<2*n;j++)
		{
			if(j==n+i)
				mat[i][j]=1.0;
			else
				mat[i][j]=0.0;
		}
	}
	FOR(i,n)
	{
		FOR(j,n)
		{
			if(j!=i)
			{
				if(!mat[i][i])
				{
					interchange(n,2*n,mat,i);		
				}					
				float ratio=mat[j][i]/mat[i][i];
				FOR(k,2*n)
				{
					mat[j][k]-=ratio*mat[i][k];
				}				
			}			
		}
	}
	FOR(i,n)
		{
			float a=mat[i][i];
			FOR(k,2*n)
				mat[i][k]/=a;
		}
	cout<<"Inverse Matrix:\n";
	for(int a=0;a<n;a++)
		{
			for(int b=n;b<2*n;b++)
				cout<<mat[a][b]<<" ";
			cout<<"\n";
		}
}

int main()
{
	int n;
	cout<<"enter order of matrix";
	cin>>n;
//	int d=2*n;
	float mat[10][20],mat2[10][20];
	FOR(i,n)
		FOR(j,n)
		{
			cin>>mat[i][j];
			mat2[i][j]=mat[i][j];
		}
			
	print(n,mat);
	
	//cout<<"determinant: "<<det<<"\n";
	//print(n,mat);
	int c=0;
	int flag=0;
	float det;
	FOR(i,n)
	{
		c=0;
		FOR(j,n)
		{
			if(!mat[j][i])
				c++;
		}
		if(c==n)
		{
			det=0;
			flag=1;
			break;
		}
			
	}
	if(!flag)		
		det=determinant(n,mat);
	cout<<"determinant:"<<det;
	if(det)
		inverse(n,mat2);	
	else
		cout<<"Determinant is 0.Inverse not possible\n";
		
	return 0;
}