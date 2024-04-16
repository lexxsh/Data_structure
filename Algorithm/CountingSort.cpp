#include <iostream>
using namespace std;

void countingSort(int a[], int n, int m) {
    const int MAX_N = 1000; // 배열의 최대 크기 설정
    const int MAX_M = 1000; // 배열의 최대 크기 설정
    int count[MAX_M + 1] = { 0 }; // count[]를 0으로 초기화

    // 원소의 개수를 세어 count[]에 저장
    for (int i = 1; i <= n; ++i) {
        count[a[i]]++;
    }

    // 원소가 들어갈 위치 계산
    for (int j = 2; j <= m; ++j) {
        count[j] += count[j - 1];
    }

    int b[MAX_N]; // 임시 배열 b 생성

    // a[]의 원소를 b[]의 미리 계산된 위치로 이동
    for (int i = n; i >= 1; --i) {
        b[count[a[i]]] = a[i];
        count[a[i]]--;
    }

    // b[]를 a[]로 이동
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i];
    }
}

int main() {
    int a[] = { 0, 2, 4, 1, 3, 2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]) - 1;
    int m = 4; // 배열 a[]의 원소 중 가장 큰 값

    countingSort(a, n, m);

    cout << "정렬된 배열: ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
