#include<iostream>
using namespace std;

void selectionsort(int n, int arr[]) {
	int i, j, small;
	for (i = 0; i < n - 1; i++) {
		small = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[small])small = j;
		}
		swap(arr[i], arr[small]);
		cout << i << "번째 정렬: ";
		for (int k = 0; k < n; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
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
	selectionsort(N, arr);
	delete[] arr;
	return 0;
}