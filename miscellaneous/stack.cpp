#include <iostream>
#include <stdlib.h>

using namespace std;

class Stack
{
private:
	int *p;
	int top, length;

public:
	Stack(int = 0);
	~Stack();

	void push(int);
	int pop();
	void display();
};

Stack::Stack(int size)
{
	top = -1;
	length = size;
	if(size == 0)
		p = 0;
	else
		p = new int[length];
}

Stack::~Stack()
{
	if(p!= 0)
		delete [] p;
}

void Stack::push(int ele)
{
	if(p == 0)
	{
		cout<<"Stack is empty\n";
		cout<<"Enter the size of the stack\n";
		cin>>length;
		p = new int[length];
	}
	if(top == length-1)/*if top reaches to max*/
	{
		cout<<"Stack full. Cannot push element.\n";
		return;
	}
	else
	{
		top++;
		p[top] = ele;
	}
}

int Stack::pop()
{
	if(p == 0 || top == -1)
	{
		cout<<"Stack empty. Cannot pop.\n";
		return -1;
	}
	int ret = p[top];
	top--;
	return ret;
}

void Stack::display()
{
	for(int i =0; i<=top; i++)
		cout<<p[i]<<" ";
	cout<<endl;
}

int main()
{
	int choice;
	cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n";
	Stack s1;
	int ele, ret_num;
	do
	{
		cin>>choice;
		switch(choice)
		{
			case 1:
			cout<<"Enter the element\n";
			cin>> ele;
			s1.push(ele);
			break;

			case 2:
			ret_num = s1.pop();
			if(ret_num != -1)
				cout<<"Element popped is: "<<ret_num<<"\n";
			else
				break;
			break;

			case 3:
			s1.display();
			break;

			case 4:
			exit(0);
		}
	}while(choice!=4);
}