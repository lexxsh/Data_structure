#pragma once
#define MAX_ITEMS 100


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