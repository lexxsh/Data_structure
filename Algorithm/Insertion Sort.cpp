#include<iostream>
using namespace std;

void insertionsort(int n, int arr[]) {
	int key,i,j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j+1] = arr[j];
		}
		cout << i << "��° ����: ";
		for (int k = 0; k < n; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
		arr[j+1] = key;
	}
}
int main() {
	int N;
	cout << "������ ������ �Է����ּ���: ";
	cin >> N;
	int* arr = new int[N];
	cout << "�迭�� �Է����ּ���: ";
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	insertionsort(N, arr);
	delete[] arr;
	return 0;
}