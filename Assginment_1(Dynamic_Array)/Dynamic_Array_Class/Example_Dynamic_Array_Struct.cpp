#include "dynArr.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

void initDynArr(dyArr* da, int cap)
{
	assert(cap >= 0); //음수용량을 방지하기 위한 assert사용
	da->capacity = cap; //초기용량을 cap으로 설정
	da->size = 0;       //초기 요소수를 0으로 설정
	da->data = (TYPE*)malloc(da->capacity * sizeof(TYPE)); //데이터 배열에 메모리할당
	assert(da->data != 0);//메모리할당이 성공적으로 이루어 졌는지 확인
}

void freeDynArr(dyArr* da)
{
	assert(da != 0); //배열이 유효한지 확인
	free(da->data); //메모리를 해제
	da->capacity = 0; //용량수 초기화
	da->size = 0; //크기를 0으로 초기화
}

void addDynArr(dyArr* da, TYPE val)
{
	if (da->size >= da->capacity)
		_dyArrDoubleCapacity(da);//배열이 가득차면 두배로 용량 증가
	da->data[da->size] = val;//배열에 요소를 추가해준다
	da->size++;//요소 크기 증가
}

TYPE getDynArr(dyArr* da, int idx)
{
	assert((sizeDynArr(da) > idx) && (idx >= 0)); //유효한 인덱스인지 확인
	return da->data[idx]; //인덱스의 데이터를 반환해준다.
}

int sizeDynArr(dyArr* da)
{
	return da->size; //size 값을 반환
}

void _dyArrDoubleCapacity(dyArr* da)
{
	TYPE* oldbuffer = da->data;  // 이전 데이터 배열의 주소 저장
	int oldsize = da->size;  // 이전 크기 저장
	initDynArr(da, 2 * da->capacity);  // 용량을 두 배로 늘리고 초기화
	for (int i = 0; i < oldsize; i++)
		da->data[i] = oldbuffer[i];  // 이전 데이터를 새 배열에 복사
	da->size = oldsize;  // 크기 설정
	free(oldbuffer);  // 이전 데이터 배열의 메모리 해제
}
