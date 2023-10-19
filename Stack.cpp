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
    Stack myStack;  // 스택 객체 생성

    // 스택이 비어있는지 확인
    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }       

    // 스택에 데이터 추가
    for (int i = 1; i <= 10; i++) {
        myStack.push(i);
        cout << "Pushed: " << i << endl;
    }

    // 스택이 가득 차 있는지 확인
    if (myStack.isFull()) {
        cout << "Stack is full." << endl;
    }
    else {
        cout << "Stack is not full." << endl;
    }

    // 스택에서 데이터 제거
    while (!myStack.isEmpty()) {
        int item;
        myStack.pop(item);
        cout << "Popped: " << item << endl;
    }

    return 0;
}