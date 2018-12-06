
#include<bits/stdc++.h>
using namespace std;
#include<stdlib.h>
#include<stdio.h>

typedef struct node{
	int data;
	node *left;
	node *right;
	node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
}node;


/*node* create_node(node *root,int key)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}*/


node* insert(node *root,int key)
{
	if(!root){
		//root=create_node(root,key);
		root=new node(key);
		return root;
	}
	if(key<root->data)
		root->left = insert(root->left,key);	
	
	else if(key>root->data) 
		root->right =  insert(root->right,key);	
	return root;
}

node* search(node *root,int key)
{
	if(!root)
		return NULL;
	if(root->data == key)
		return root;
	if(key > root->data)
		return search(root->right,key);
	if(key < root->data)
		return search(root->left,key);
}

void inorder_traversal(node *root)
{
	if(!root)
		return ;
	inorder_traversal(root->left);
	cout<<root->data<<" ";
	inorder_traversal(root->right);
}

node *inorder_successor(node *root)
{
	if(!root)
		return NULL;
	node *current=root;	
	while(current->left)
		current=current->left;
	return current;
}

node *delete_node(node *root,int key)
{
	if(!root)
		return NULL;
	else if( key < root->data){
		root->left=delete_node(root->left,key);
	}
	else if(key > root->data)
		root->right=delete_node(root->right,key);
	//if(root->data==key)
	else	
	{
		if(!root->right){ //only left child of node to be deleted
			node *temp=root->left;
			free(root);		
			return temp;
		}
		else if(!root->left){ //only right child of node to be deleted
			node *temp=root->right;
			free(root);		
			return temp;
		}				
		else{ //both right and left child present
			node *temp=inorder_successor(root->right) ;//find inorder successor of root	
			root->data=temp->data;
			root->right=delete_node(root->right,temp->data);
			return root;	
		}
	}	
}

int height(node *root)
{
	if(!root)
		return 0;
	int height=0;	
	queue <node *> q;
	q.push(root);	
	while(1){		
		
		int nodes_in_queue=q.size();	
		if(nodes_in_queue==0)
			return height;
		height++;
		while(nodes_in_queue)
		{
			node *temp=q.front();
			q.pop();			
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			nodes_in_queue--;
		}
	}

}


/*
node *insert_option(node *root)
{
	int data;
	cout<<"Enter key value to insert";
	cin>>data;
	return insert(root,data);	
	
}
node *search_option(node *root)
{
	return root;
}
node *height_option(node *root)
{
	return root;
}
node *delete_option(node *root)
{
	return root;
}
*/
/*void inorder(node *root)
{
	stack<node *>s;
	node *tmp=root;
	s.push(tmp);
	while(!s.empty())
	{
		node *t=s.top();
		while(t->left)
		{
			s.push(t->left);
			t=t->left;
		}
		t=s.top();
		s.pop();
		cout << t->data << ",";
		t=s.top();
		if(t->right){
			s.push(t->right);		
		}
		else{
			//t=s.top();
			//while()			
			s.pop();
			cout << t->data << ",";
					
		}
	}
}*/
void inorder(node *root)
{
	stack<node *>s;
	node *t=root;
	s.push(t);
	t=t->left;	
	while(!s.empty() || t)
	{	//push(t);
//		t=s.top();
		while(t){
			s.push(t);	
			t=t->left;		
		}
		t=s.top();
		cout << t->data<<" ";
		s.pop();
		/*if(t->right){		
			t=t->right;
			s.push(t);
		}
		t=s.top();
		s.push(t->right);*/
		t=t->right;
	}
}

void preorder(node *root)
{
	stack<node *>s;
	node *t=root;
	s.push(t);
	while(!s.empty())
	{
		t=s.top();
		s.pop();		
		cout<<t->data<<"\n";
		if(t->right)
			s.push(t->right);
		if(t->left)
			s.push(t->left);

	}
}

void postorder(node *root)//LRN
{
	stack<node *>s1,s2; //push left nodes in s1, right nodes in s2
	node *t=root;
	s1.push(t);
	while(!s1.empty())
	{	
//		t=s2.top();		
		while(t->left)
		{
			s1.push(t->left);
			t=t->left;		
		}
				
		s2.push(s1.top());
		s1.pop();
		if(s2.top()->right)
			{
				t=s2.top()->right;
				s1.push(t);				
				continue;
				
			}	
		else{
			while(!s2.empty())
			{
				cout<< s2.top()->data<<" ";		
				s2.pop();
				//t=t->right;
				//s1.push(t->right);
			}
			cout<<s1.top()<<" ";
			s1.pop();
			s1.push(t->right);
		}
		
	}
}


int main()
{
	node *root=NULL;
	int option;	
	cout<< "Enter 1 for insert, 2 for search, 3 for height, 4 for delete,5 for inorder traversal, 6 for preorder traversal,7 for postorder traversal,0 to exit\n";
	cin>>option;	
	while(1)
	{
		int data;		
		switch(option){
			case 1:
				cout<<"enter value to insert: ";
				cin >> data;				
				root=insert(root,data);
				break;
			case 2:
				cout<<"enter value to search: " ;
				cin >> data;				
				if(search(root,data))
					cout<<"node present\n";
				else
					cout<<"node not present\n";
				break;
			case 3:cout<<"height:"<<height(root)<<"\n";
				break;
			case 4:	
				cout<<"enter value to delete: ";
				cin >> data;			
				if(search(root,data)){
					root=delete_node(root,data);
					cout<<"Inorder traversal:\n";				
					inorder(root);
					cout<<"\n";	
				}
				else
					cout<<"node not present\n";				
				break;
		
			case 5:
				cout<<"Inorder traversal:\n";			
				inorder(root);
				cout<<"\n";
				break;
			case 6:
				cout<<"Preorder traversal:\n";			
				preorder(root);
				cout<<"\n";
				break;
			case 7:
				cout<<"Postorder traversal:\n";			
				postorder(root);
				cout<<"\n";
				break;

			default : exit(1);
		}
		cout<< "Enter 1 for insert, 2 for search, 3 for height, 4 for delete,5 for printing inorder traversal 0 to exit\n";
		cin>>option;	
	}
/*root=insert(root,123);
root=insert(root,145);
root=insert(root,1000);
root=insert(root,10);
root=insert(root,15);
inorder_traversal(root);
cout<<"\n";
if(search(root,123))
	root=delete_node(root,123);		
else
	cout<<"node not present\n";
inorder_traversal(root);*/
	return 1;	
}
