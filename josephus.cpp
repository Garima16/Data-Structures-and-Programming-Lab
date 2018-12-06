#include <iostream>
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

node *insert_node(int data,node *head)
{
	node *t=new node(data);
	node *p=head->next;
	head->next=t;
	if(!p)
	{
		t->next=head;
	}
	else{
		
		t->next=p;	
	}
	head=t;
	return head;
}

int josephus(node *head,int start,int k)
{
	while(head->data!=start)
		head=head->next;
	while(head->next!=head)
	{
		node *d=head;
		for(int a=1;a<=k-2;a++)
		{
			d=d->next;
		}
		node *f=d->next;
		d->next=f->next;
		delete(f);
		head=d->next;
	}
	return head->data;
}

int main()
{
	int n,start,k;
	cout<<"Enter number of nodes,starting position, skipping number";
	cin>>n>>start>>k;
	if(n<=1)
	{
		return main();
	}
	node *head=new node(1);
	for(int a=2;a<=n;a++)
	{
		head=insert_node(a,head);
	}
	cout<<"Safe position : "<<josephus(head,start,k)<<"\n";
	return 0;
}