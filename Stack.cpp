#include<iostream>
#define MAX_ITEMS 10
using namespace std;

class Stack {
public:
	Stack() {
		top = -1;
	}
	void makeEmpty() {
		top = -1;
	}
	bool isEmpty() const {
		return (top == -1);
	}
	bool isFull()const {
		return (top == MAX_ITEMS - 1);
	}
	void push(int newItem) {
		top++;
		items[top] = newItem;
	}
	void pop(int& item) {
		item = items[top];
		top--;
	}
private:
	int top;
	int items[MAX_ITEMS];
};

int main() {
    Stack myStack;  // ���� ��ü ����

    // ������ ����ִ��� Ȯ��
    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }       

    // ���ÿ� ������ �߰�
    for (int i = 1; i <= 10; i++) {
        myStack.push(i);
        cout << "Pushed: " << i << endl;
    }

    // ������ ���� �� �ִ��� Ȯ��
    if (myStack.isFull()) {
        cout << "Stack is full." << endl;
    }
    else {
        cout << "Stack is not full." << endl;
    }

    // ���ÿ��� ������ ����
    while (!myStack.isEmpty()) {
        int item;
        myStack.pop(item);
        cout << "Popped: " << item << endl;
    }

    return 0;
}