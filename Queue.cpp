#include<iostream>
using namespace std;
template <class ItemType>
class Queue
{
private:
	int front;
	int rear;
	int allocSize;
	ItemType* items;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	void enqueue(ItemType);
	void dequeue(ItemType&);
	void getfront();
};

template<class ItemType>
Queue<ItemType>::Queue() {
	allocSize = 50;
	front = 0;
	rear = 0;
	items = new ItemType[allocSize];
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
	delete[] items;
}

template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	return (rear == front);
}

template<class ItemType>
bool Queue<ItemType>::isFull() const
{
	return ((rear + 1) % allocSize == front);
}

template<class ItemType>
void Queue<ItemType>::enqueue(ItemType newItem)
{
	rear = (rear + 1) % allocSize;
	items[rear] = newItem;
}

template<class ItemType>
void Queue<ItemType>::dequeue(ItemType& item)
{
	front = (front + 1) % allocSize;
	item = items[front];
}
template<class ItemType>
void Queue<ItemType>::getfront()
{
	return front;
}

int main() {
	Queue<int>  myQueue;
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	int front;
	myQueue.dequeue(front);
	std::cout << "Dequeue: " << front<< std::endl;
	myQueue.dequeue(front);
	std::cout << "Dequeue: " << front << std::endl;
	myQueue.enqueue(4);
	for (int i = 1; i <= 5; i++) {
		myQueue.enqueue(i);
	}

	while (!myQueue.isEmpty()) {
		myQueue.dequeue(front);
		std::cout << "Dequeue: " <<front<< std::endl;
	}
	return 0;
} 