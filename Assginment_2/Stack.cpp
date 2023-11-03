#include "Stack.h"

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
