#include<iostream>
using namespace std;

int BinarySearch1(int A[], int low, int high, int v) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (A[mid] == v)
			return mid;
		else if (A[mid] < v)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int BinarySearch2(int A[], int low, int high, int v) {
	if (low > high)
		return -1;
	int mid = low + (high - low) / 2;
	if (A[mid] == v)
		return mid;
	else if (A[mid] < v)
		return BinarySearch2(A, mid + 1, high, v);
	else
		return BinarySearch2(A, low, mid - 1, v);
}

int main() {
	int A[5] = { 3, 6, 8, 9, 17};
	cout << "A1: " << BinarySearch1(A, 3, 5, 9) << endl;
	cout << "A2: " << BinarySearch2(A, 3, 5, 9) << endl;


}