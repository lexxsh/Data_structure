#include "array.h"
#include<assert.h>
#include<iostream>

void DynamicArray::doubleCapacity()
{
	int* old = m_data;
	int oldsize = m_size;
	int newCap = 2 * m_capacity;
	m_data = new int[newCap];
	for (int i = 0; i < oldsize; i++)
		m_data[i] = old[i];
	m_size = oldsize;
	m_capacity = newCap;
	delete(old);
}

DynamicArray::DynamicArray(int initailCapcity)
{
	assert(m_capacity >= 0);
	m_capacity = initailCapcity;
	m_size = 0;
	m_data = new int[m_capacity];
	assert(m_data != 0);
}

DynamicArray::~DynamicArray()
{
}

void DynamicArray::add(int val)
{
	if (m_size >= m_capacity) doubleCapacity();
	m_data[m_size] = val;
	m_size++;
}

int DynamicArray::get(int idx)
{
	assert(idx < m_size&& idx >= 0);
	return m_data[idx];
}

void DynamicArray::put(int idx, int val)
{
	assert(idx < m_size&& idx >= 0);
	m_data[idx] = val;
}

void DynamicArray::remove(int idx)
{
	assert(idx < m_size&& idx >= 0);
	for (int i = idx; i < m_size + 1; i++)
		m_data[i] = m_data[i + 1];
	m_size--;
}

int DynamicArray::size() const
{
	return m_size;
}