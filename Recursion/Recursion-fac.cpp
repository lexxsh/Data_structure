#include<iostream>
using namespace std;
int fact(int n) {
	if (n == 0)
		return 1;
	else return fact(n - 1) * n;
}

int main(void) {
	int num,val;
	cin >> num;
	val = fact(num);
	cout << "fact = " << val << endl;
	return 0;
}