#include<iostream>
#include<assert.h>
using namespace std;

class DynamicArray {
private:
	int* arr;
	int size;
	int capacity;

	void doubleCapacity() {
		capacity *= 2;
		int* newArr = new int[capacity];
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}
public:
	DynamicArray(int initialCapacity = 10) {
		capacity = initialCapacity;
		size = 0;
		arr = new int[capacity];
	}
	~DynamicArray() {
		delete[] arr;
	}
	void append(int value) {
		if (size >= capacity) doubleCapacity();
		arr[size] = value;
		size++;
	}
	void put(int index, int val) {
		assert(index >= 0 && index < size);
		arr[index] = val;
	}
	void insert(int index, int value) {
		for (int i = size; i > index; i--) {
			arr[i] = arr[i - 1];
		}
		arr[index] = value;
		size++;
	}
	void remove(int index) {
		assert(index >= 0 && index < size);
		for (int i = index; i < size-1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}

	int get(int index) {
		assert(index >= 0 && index < size);
		return arr[index];
	}
	int getSize() {
		return size;
	}
};

int main() {
	DynamicArray arr;
	for (int i = 0; i < 10; i++) {
		arr.append(i);
	}
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr.get(i) << " ";
	}
	cout << endl;
	arr.put(0, 999);
	arr.remove(3);
	arr.insert(2, 999);
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr.get(i) << " ";
	}
	cout << endl;
}

