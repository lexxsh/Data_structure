#include<iostream>
using namespace std;

void decToBin(int num, int base) {
	if (num > 0) {
		decToBin(num / base, base);
		cout << num % base;
	}
}
int main() {
	int a, b;
	cout << "a , b = ";
	cin >> a >> b;
	decToBin(a, b);
}