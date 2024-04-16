#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    int h = 1;
    // ù ��° h �� ���
    while (h < n) {
        h = 3 * h + 1;
    }

    // h ���� ���ҽ�Ű�� ����
    while (h > 0) {
        // ���� ���� ����
        for (int i = h + 1; i <= n; ++i) {
            int v = arr[i];
            int j = i;
            // ���� ����
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

    cout << "���ĵ� �迭: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
 