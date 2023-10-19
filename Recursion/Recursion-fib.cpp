#include<iostream>
using namespace std;

int Fib(int a, int b, int num) {
	if (num == 1)
		return a;
	if (num == 2)
		return b;
	return Fib(a, b, num - 1) + Fib(a, b, num - 2);
}
int main() {
	int a, b, c;
	cout << "a, b, c = ";
	cin >> a >> b >> c;
	cout << Fib(a, b, c) << endl;
	return 0;
}