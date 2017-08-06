//C++ program for converting binary tree to Doubly linked list
#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	node* right;
	node* left;
};

node* binarytodllUtil(node* root)
{
	if (root == NULL)
		return root;

	if(root->left!=NULL)
	{
		node* left = binarytodllUtil(root->left);

		for(; left->right!=NULL; left=left->right);

		left->right = root;
		root->left = left;
	}

	if(root->right!=NULL)
	{
		node* right = binarytodllUtil(root->right);

		for(; right->left!=NULL; right=right->left);

		right->left = root;
		root->right = right;
	}

	return root;
}

node* binarytodll(node* root)
{
	if (root == NULL)
		return root;

	root = binarytodllUtil(root);

	while(root->left!=NULL)
		root = root->left;
	return root;
}

node* newNode(int data)
{
	node* new_node = new node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void printdll(node* root)
{
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root = root->right;
	}
}

int main()
{
	node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->left->right = newNode(30);
	root->left->right->right = newNode(20);
	root->left->right->right->left = newNode(16);
	root->right->left = newNode(36);

	root = binarytodll(root);

	printdll(root);
	return 0;
}