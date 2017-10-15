#include <iostream>
#include <stdio.h>

using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetNewNode(int data)
{
	BstNode* newNode= new BstNode();
	newNode->data= data;
	newNode->left= newNode->right= NULL;
	return newNode;
}

BstNode* insert(BstNode* root, int data);
bool search(BstNode* root, int data);
BstNode* deleteNode(BstNode* root, int data);
void display(BstNode* root);
BstNode* findMin(BstNode* node);


int main()
{
	int n, data;
	BstNode* root= NULL; //Creating an empty tree
	cout<<"Building a binary search tree. Process will start now.\n";
	cout<<"Enter the number of nodes in the tree.\n";
	cin>>n;
	for(int i= 0; i< n; i++)
	{
		cout<<"Enter node "<<i+1<<" to be inserted\n";
		cin>>data;
		root= insert(root, data);

	}
	display(root);

	int choice,newData;
	bool result;

	do
	{
		cout<<"\n\nThis program provides you with two options till now.\n1) Search\n2) Delete\n3) Exit\nChoose which operation you want to perform\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the number you want to search\n";
				cin>>newData;
				result= search(root, newData);
				if(result== true)
					cout<<"NUMBER FOUND!\n";
				else
					cout<<"NUMBER NOT FOUND!\n";
				break;

			case 2:
				cout<<"Enter the number you want to delete\n";
				cin>>newData;
				root= deleteNode(root, newData);
				display(root);
				break;

			case 3:
				break;

			default:
				cout<<"Enter a valid option.\n";
		}
	}while(choice!=3);
	return 0;
}

BstNode* insert(BstNode* root, int data)
{
	if(root==NULL)
		root= GetNewNode(data);
	else if(data<= root->data)
		root->left= insert(root->left, data);
	else
		root->right= insert(root->right, data);
	return root;
}

void display(BstNode* root)
{
	if(root!=NULL)
	{
		int data= root->data;
		cout<<data<<" ";
		display(root->left);
		display(root->right);
	}
	
}

bool search(BstNode* root, int data)
{
	if(root==NULL)
		return false;
	else if(root->data== data)
		return true;
	else if(data< root->data)
		search(root->left, data);
	else
		search(root->right, data);
}

BstNode* deleteNode(BstNode* root, int data)
{
	if(root==NULL)
	{
		cout<<"Number does not exist. Try again.\n";
		return root;
	}
	else if(data< root->data)
		root->left= deleteNode(root->left, data);
	else if(data> root->data)
		root->right= deleteNode(root->right, data);
	else
	{
		//Case1: no child
		if(root->left== NULL && root->right== NULL)
		{
			delete root;
			root=NULL;
		}
		//Case 2:One child
		else if(root->left== NULL)
		{
			struct BstNode* temp= root;
			root= root->right;
			delete temp;
		}
		else if(root->right== NULL)
		{
			struct BstNode* temp= root;
			root= root->left;
			delete temp;
		}
		//Case 3: two children
		else
		{
			struct BstNode* temp= findMin(root->right);
			root->data= temp->data;
			root->right= deleteNode(root->right, temp->data);
		}
	}
	return root;
}

BstNode* findMin(BstNode* node)
{
	struct BstNode* current= node;
	while(current->left!=NULL)
	{
		current= current->left;
	}
	return current;
}