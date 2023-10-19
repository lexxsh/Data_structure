#include<iostream>
using namespace std;

int largest(const int list[], int lowerIndex, int upperIndex) {
	int max;
	if (lowerIndex == upperIndex)
		return list[lowerIndex];
	else
	{
		max = largest(list, lowerIndex + 1, upperIndex);
		if (list[lowerIndex] >= max)
			return list[lowerIndex];
		else
			return max;
	}
}
int main() {
	int arr[4] = { 5, 56, 12,8 };
	cout << largest(arr, 0, 3) << endl;
}