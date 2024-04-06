#include<iostream>
using namespace std;
int largest(int list[], int size) {
	if (size == 1)
		return list[0];
	else {
		int max = largest(list, size - 1);
		if (max > list[size - 1])
			return max;
		else
			return list[size - 1];
	}
}
int main() {
	int A[] = { 3,2,6,44,22,2 };
	cout << "largest : " << largest(A, 6);
}