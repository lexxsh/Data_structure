#include<iostream>
using namespace std;

void BubbleSort(int n, int arr[]) {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j+1] < arr[j]) swap(arr[j], arr[j+1]);
		}
		cout << n - i << "��° ����: ";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}
int main() {
	int N;
	cout << "�迭�� ���� ������ �Է����ּ���: ";
	cin >> N;
	int* arr = new int[N];
	cout << "�迭�� �Է����ּ���: ";
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	BubbleSort(N, arr);
	delete[] arr;
	return 0;
}