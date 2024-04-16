#include<iostream>
using namespace std;

void insertionsort(int n, int arr[]) {
	int key,i,j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j+1] = arr[j];
		}
		cout << i << "번째 정렬: ";
		for (int k = 0; k < n; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
		arr[j+1] = key;
	}
}
int main() {
	int N;
	cout << "숫자의 개수를 입력해주세요: ";
	cin >> N;
	int* arr = new int[N];
	cout << "배열을 입력해주세요: ";
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	insertionsort(N, arr);
	delete[] arr;
	return 0;
}