#include <iostream>
using namespace std;

void countingSort(int a[], int n, int m) {
    const int MAX_N = 1000; // �迭�� �ִ� ũ�� ����
    const int MAX_M = 1000; // �迭�� �ִ� ũ�� ����
    int count[MAX_M + 1] = { 0 }; // count[]�� 0���� �ʱ�ȭ

    // ������ ������ ���� count[]�� ����
    for (int i = 1; i <= n; ++i) {
        count[a[i]]++;
    }

    // ���Ұ� �� ��ġ ���
    for (int j = 2; j <= m; ++j) {
        count[j] += count[j - 1];
    }

    int b[MAX_N]; // �ӽ� �迭 b ����

    // a[]�� ���Ҹ� b[]�� �̸� ���� ��ġ�� �̵�
    for (int i = n; i >= 1; --i) {
        b[count[a[i]]] = a[i];
        count[a[i]]--;
    }

    // b[]�� a[]�� �̵�
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i];
    }
}

int main() {
    int a[] = { 0, 2, 4, 1, 3, 2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]) - 1;
    int m = 4; // �迭 a[]�� ���� �� ���� ū ��

    countingSort(a, n, m);

    cout << "���ĵ� �迭: ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
