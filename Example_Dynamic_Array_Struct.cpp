#include "dynArr.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

void initDynArr(dyArr* da, int cap)
{
	assert(cap >= 0); //�����뷮�� �����ϱ� ���� assert���
	da->capacity = cap; //�ʱ�뷮�� cap���� ����
	da->size = 0;       //�ʱ� ��Ҽ��� 0���� ����
	da->data = (TYPE*)malloc(da->capacity * sizeof(TYPE)); //������ �迭�� �޸��Ҵ�
	assert(da->data != 0);//�޸��Ҵ��� ���������� �̷�� ������ Ȯ��
}

void freeDynArr(dyArr* da)
{
	assert(da != 0); //�迭�� ��ȿ���� Ȯ��
	free(da->data); //�޸𸮸� ����
	da->capacity = 0; //�뷮�� �ʱ�ȭ
	da->size = 0; //ũ�⸦ 0���� �ʱ�ȭ
}

void addDynArr(dyArr* da, TYPE val)
{
	if (da->size >= da->capacity)
		_dyArrDoubleCapacity(da);//�迭�� �������� �ι�� �뷮 ����
	da->data[da->size] = val;//�迭�� ��Ҹ� �߰����ش�
	da->size++;//��� ũ�� ����
}

TYPE getDynArr(dyArr* da, int idx)
{
	assert((sizeDynArr(da) > idx) && (idx >= 0)); //��ȿ�� �ε������� Ȯ��
	return da->data[idx]; //�ε����� �����͸� ��ȯ���ش�.
}

int sizeDynArr(dyArr* da)
{
	return da->size; //size ���� ��ȯ
}

void _dyArrDoubleCapacity(dyArr* da)
{
	TYPE* oldbuffer = da->data;  // ���� ������ �迭�� �ּ� ����
	int oldsize = da->size;  // ���� ũ�� ����
	initDynArr(da, 2 * da->capacity);  // �뷮�� �� ��� �ø��� �ʱ�ȭ
	for (int i = 0; i < oldsize; i++)
		da->data[i] = oldbuffer[i];  // ���� �����͸� �� �迭�� ����
	da->size = oldsize;  // ũ�� ����
	free(oldbuffer);  // ���� ������ �迭�� �޸� ����
}
