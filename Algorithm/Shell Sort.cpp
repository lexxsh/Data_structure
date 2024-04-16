#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    int h = 1;
    // 첫 번째 h 값 계산
    while (h < n) {
        h = 3 * h + 1;
    }

    // h 값을 감소시키며 진행
    while (h > 0) {
        // 삽입 정렬 수행
        for (int i = h + 1; i <= n; ++i) {
            int v = arr[i];
            int j = i;
            // 삽입 정렬
            while (j > h && arr[j - h] > v) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = v;
        }
        h /= 3;
    }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    cout << "정렬된 배열: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
 