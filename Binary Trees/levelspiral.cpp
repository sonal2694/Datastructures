// C++ program for level order traversal in binary form
#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

int height(node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);

		if(lheight>rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
}

void printGivenLevel(node* root, int level, int ltr)
{
	if (root == NULL)
		return;

	if (level == 1)
		cout<<root->data<<" ";

	else if(level>1)
	{
		if(ltr)
		{
			printGivenLevel(root->left, level-1, ltr);
			printGivenLevel(root->right, level-1, ltr);
		}
		else
		{
			printGivenLevel(root->right, level-1, ltr);
			printGivenLevel(root->left, level-1, ltr);
		}
	}
}

void printLevelspiral(node* root)
{
	int h = height(root);
	int i;
	bool ltr = false;

	for(i = 1; i<=h; i++)
	{
		printGivenLevel(root, i, ltr);
		ltr = !ltr;
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
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);

	printLevelspiral(root);
	return 0;
}