//C++ program for level order traversal
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};

void printLevelorder(node* root)
{
	if (root == NULL)
		return;

	queue<node *> q;

	q.push(root);

	while(q.empty() == false)
	{
		node *temp = q.front();
		cout<< temp->data<< " ";
		q.pop();

		if(temp->left != NULL)
			q.push(temp->left);

		if(temp->right != NULL)
			q.push(temp->right);
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

	printLevelorder(root);
	return 0;
}