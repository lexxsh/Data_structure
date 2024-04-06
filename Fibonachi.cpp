#include<iostream>
using namespace std;
int fib(int n) {
	cout << n << endl;
	if (n <= 1)
		return 0;
	else return fib(n - 1) + fib(n - 2);
}

int main() {
	fib(5);
}