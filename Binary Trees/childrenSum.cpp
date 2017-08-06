//C++ program to check for binary tree property in a binary tree.
#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

int checksumproperty(node* root)
{
	int l = 0, r = 0; 
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return 1;

	else
	{
		if(root->right != NULL)
			r = root->right->data;

		if(root->left != NULL)
			l = root->left->data;

		if((root->data == l+r) && checksumproperty(root->left) && checksumproperty(root->right))
			return 1;
		else
			return 0;
	}
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
	root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);

	if (checksumproperty(root))
		cout<<"Binary Tree satisfies check sum property.\n";
	else
		cout<<"Binary Tree does not satisfies check sum property.\n";
	return 0;
}