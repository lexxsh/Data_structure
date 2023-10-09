#pragma once

class DynamicArray {
private:
	int* m_data;
	int m_size;
	int m_capacity;
	int m_numDeleted;
	void doubleCapacity();

public:
	DynamicArray(int initailCapcity = 4);
	~DynamicArray();

	void add(int val);
	int get(int idx);
	void put(int idx, int val);
	void remove(int idx);
	int size() const;
};
