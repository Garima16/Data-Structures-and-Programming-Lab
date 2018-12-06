#include <iostream>
#include <climits>
#define INF 9999999
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
}node;

node *arr[12]={NULL};

void insert_node(int data,int index)
{
	node *t=new node(data);
	//insert at end
	if(!arr[index]){
		arr[index]=t;
	}
	else
	{
		node *p=arr[index];
		while(p->next)
			p=p->next;
		p->next=t;
	}
}


void print_mat(int mat[][4])
{
	// int i=0,j=0;
	FOR(i,4)
		{
			FOR(j,4)
			{
				if(i==j){
					mat[i][j]=0;
				}				
				cout<<mat[i][j]<<" ";
			}
			cout<<"\n";
		}
}
void copy_to_another(int tomat[][4],int frommat[][4])
{
	FOR(i,4)
	{
		FOR(j,4)
			tomat[i][j]=frommat[i][j];
	}
}

void print_list_arr()
{
	FOR(i,12)
	{
		node *src=arr[i];
		
		node *dest=src->next;
		node *p=dest->next;		
		cout<<"Path from "<<src->data<<" to "<<dest->data<<": "<<src->data<<"->";		
		while(p)
		{	
			cout<<p->data<<"->";
			p=p->next;	
		}
		cout<<dest->data;
		cout<<"\n\n";
	}
}


node *find_int_node(int src,int dest)
{
	//cout<<"in this"<<src<<" "<<dest;	
	FOR(i,12){
		node *p=arr[i];
		if(p->data==src && p->next->data==dest && p->next->next)
		{
			return p->next->next;
		}
	}
	return NULL;
}
void floyd_warshall(int mat[][4])
{
	int mat2[4][4];
	
	// print_mat(mat);
	// print_mat(mat2);
	FOR(k,4)
	{
		cout<<"k="<<k<<"\n";		
		int c=-1;
		FOR(i,4)
		{
			// if(i==k)
			// 	continue;
			
			FOR(j,4)
			{
				int flag=0;				
				if(i!=j)
				{
				// 	continue;
					++c;
					if( mat[i][j] > ( mat[i][k]+mat[k][j] ) )
						{
							mat2[i][j]=mat[i][k]+mat[k][j];
							node *q=find_int_node(i,k);
														
							if(q)
							{
								cout<<q->data;								
								while(q)
								{
									insert_node(q->data,c);
									q=q->next;
								}			
							}
							node *qa=find_int_node(k,j);
							if(qa)
							{
								//cout<<qa->data;
								flag=1;
								insert_node(k,c);								
								while(qa)
								{
									insert_node(qa->data,c);
									qa=qa->next;
								}			
							}
							//else
							if(!flag)
							insert_node(k,c);
						}
					else
						mat2[i][j]=mat[i][j];
				}
			}	
		}
		copy_to_another(mat,mat2);
		// print_mat(mat);

		print_list_arr();
		cout<<"\n";
		print_mat(mat2);
		// mat1=mat;
	}
	//print_mat(mat2);

}



int main()
{
	int mat[4][4]={{0,10,5,15},{INF,0,20,INF},{INF,INF,0,7},{3,INF,10,0}};
	int c=0;
	FOR(i,4)
	{
		FOR(j,4)
		{
			if(i==j)
				continue;
			insert_node(i,c);
			insert_node(j,c++);
		}
	}
	floyd_warshall(mat);
	// print_list_arr();
	return 1;
}


