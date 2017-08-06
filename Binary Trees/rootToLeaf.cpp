//C++ program to print all the root-to-leaf paths in a binary tree
#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

void printPathRecur(node *root, int paths[], int pathlen)
{
	if (root == NULL)
		return;

	paths[pathlen] = root->data;
	pathlen++;

	if(root->left == NULL && root->right == NULL)
	{
		int i;
		for (i = 0; i < pathlen; i++)
			cout<<paths[i]<< " ";
		cout<<"\n";
	}
	else
	{
		printPathRecur(root->left, paths, pathlen);
		printPathRecur(root->right, paths, pathlen);
	}
}

void printpaths(node *root)
{
	int paths[1000];
	printPathRecur(root, paths, 0);
}

node* newNode(int data)
{
	node *new_node = new node;
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

int main()
{
	node *root;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);

	printpaths(root);
	return 0;
}