#include "array.h"
#include<assert.h>
void DynamicArray::doubleCapacity()
{
	int* old_data = m_data;
	int old_size = m_size;
	int newCap = 2 * m_capacity;
	m_data = new int[newCap];
	for (int i = 0, j = 0; i <= old_size+m_numDeleted; i++){
		if(old_data[i] !=-1){
			m_data[j] = old_data[i];
			j++;
		}
	}
	m_size = old_size;
	m_capacity = newCap;
	m_numDeleted = 0;
}

DynamicArray::DynamicArray(int initailCapcity)
{
	assert(m_capacity >= 0);
	m_capacity = initailCapcity;
	m_size = 0;
	m_numDeleted = 0;
	m_data = new int[m_capacity];
	assert(m_data != 0);
}

DynamicArray::~DynamicArray()
{
	delete[] m_data;
}

void DynamicArray::add(int val)
{
	if ((m_size+m_numDeleted) > m_capacity) doubleCapacity();
	m_data[m_size+m_numDeleted] = val;
	m_size++;
}

int DynamicArray::get(int idx)
{	
	assert(idx<m_size && idx>=0);
	int count = -1;
	for(int i = 0; i < m_capacity; i++){
		if(m_data[i] != -1){
			count++;
		}
		if(count == idx){
			return m_data[i];
		}
	}
	return -1;
}
void DynamicArray::put(int idx, int val)
{
	assert(idx < m_size&& idx >= 0);
	int count = -1;
	for(int i = 0;i<m_capacity;i++){
		if(m_data[i]!=-1){
			count++;
		}
		if(count == idx){
			m_data[i] = val;
		}
	}
}

void DynamicArray::remove(int idx)
{
	assert(idx < m_size&& idx >= 0);
	int count = 0;
	for(int i = 0 ; i<idx; i++){
		if(m_data[i]==-1){
			count++;
		}
	}
	for(int i = idx; i<m_size;i++){
		if(m_data[count+i] != -1 && m_data[i] != -1){
			m_data[count+i] = -1;
			m_numDeleted++;
			m_size--;
			return;
		}
	}
	
}

int DynamicArray::size() const
{
	return m_size;
}
