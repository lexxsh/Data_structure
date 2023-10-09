#ifndef dynArr.h
#define dynArr.h
#define TYPE int //���� �迭�� ������ ���� ����

struct  dyArr
{
	TYPE* data;  //���� �迭 �����Ϳ� ���� ������
	int size;    //�迭 ���� ���� ��� ��
	int capacity;//�迭�� �ִ� �뷮
};

void initDynArr(struct dyArr* da, int cap); //���� �迭 �ʱ�ȭ
void freeDynArr(struct dyArr* da);          //���� �迭 �޸� ����
void addDynArr(struct dyArr* da, TYPE val); //�迭�� ����߰�
TYPE getDynArr(struct dyArr* da, int idx);  //�ε������� ��� ������ ����
void putDynArr(struct dyArr* da, int idx, TYPE val);//����� ������Ʈ �Լ�
int sizeDynArr(struct dyArr* da);           //�迭���� ���� ��Ҽ� ������ ����
void _dyArrDoubleCapacity(struct dyArray* da);//�迭�� �뷮�� �ι�� �ø���



#endif
