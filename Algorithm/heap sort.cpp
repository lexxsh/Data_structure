#include <iostream>
using namespace std;

void heapify(int arr[], int h, int m) {
    int v = arr[h];
    int j = 2 * h;
    while (j <= m) {
        if (j < m && arr[j] < arr[j + 1]) {
            j += 1;
        }
        if (v >= arr[j]) {
            break;
        }
        else {
            arr[j / 2] = arr[j];
        }
        j *= 2;
    }
    arr[j / 2] = v;
}

void heapSort(int arr[], int size) {
    int n = size - 1;

    // �迭�� ������ ��ȯ
    for (int i = n / 2; i >= 1; --i) {
        heapify(arr, i, n);
    }

    // �������� �ִ밪�� ��Ʈ�� �̵���Ű�� ����
    for (int i = n; i >= 1; --i) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapify(arr, 1, i - 1);
    }
}

int main() {
    int arr[] = { 0, 4, 10, 3, 5, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    cout << "���ĵ� �迭: ";
    for (int i = 1; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
