#ifndef dynArr.h
#define dynArr.h
#define TYPE int //동적 배열의 데이터 유형 정의

struct  dyArr
{
	TYPE* data;  //동적 배열 데이터에 대한 포인터
	int size;    //배열 내의 현재 요소 수
	int capacity;//배열의 최대 용량
};

void initDynArr(struct dyArr* da, int cap); //동적 배열 초기화
void freeDynArr(struct dyArr* da);          //동적 배열 메모리 해제
void addDynArr(struct dyArr* da, TYPE val); //배열에 요소추가
TYPE getDynArr(struct dyArr* da, int idx);  //인덱스에서 요소 가지고 오기
void putDynArr(struct dyArr* da, int idx, TYPE val);//요소의 업데이트 함수
int sizeDynArr(struct dyArr* da);           //배열에서 현재 요소수 가지고 오기
void _dyArrDoubleCapacity(struct dyArray* da);//배열의 용량을 두배로 늘리기



#endif
