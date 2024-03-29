#include<iostream>
#define MAX_ITEMS 100
using namespace std;

class Stack {
private:
	int top;
	int items[MAX_ITEMS];
public:
	Stack();
	~Stack();
	void makeEmpty();
	bool isEmpty() const;
	bool isFull()const;
	void push(int newItem);
	void pop();
	int getTop();
};

Stack::Stack()
{
	top = -1;
}

Stack::~Stack()
{
}

void Stack::makeEmpty()
{
	top = -1;
}

bool Stack::isEmpty() const
{
	return (top == -1);
}

bool Stack::isFull() const
{
	return (top == MAX_ITEMS - 1);
}

void Stack::push(int newItem)
{
	top++;
	items[top] = newItem;
}

void Stack::pop()
{
	top--;
}

int Stack::getTop()
{
	if (!isEmpty())
		return items[top];
}
