#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int partition(int arr[], int p, int r) {
    int low, high;
    int pivot = arr[p]; // pivot 값 설정


    low = p + 1; // low 는 pivot의 바로 다음 위치에서부터
    high = r; // high는 전달된 끝지점

    while (low <= high) {
        while (arr[low] < pivot) low++; // pivot 보다 작은 값이 나올때마다 이동
        while (arr[high] > pivot) high--; // pivot 보다 큰 값이 나올때마다 이동

        if (low <= high) { // low와 high 가 중단된 지점이 서로 위치가 역전된 지점이 아니라면
            swap(arr[low], arr[high]); // low 와 high 의 값 변경
            low++;
            high--;
        }
    }

    // 피벗과 high 위치 교환
    swap(arr[p], arr[high]);

    return high; // 피벗 위치 반환
}
int partition_median(int arr[], int p, int r) {
    int mid = p + (r - p) / 2;
    int pivot = arr[mid];

    int low = p;
    int high = r;

    while (low <= high) {
        while (arr[low] < pivot) low++;
        while (arr[high] > pivot) high--;

        if (low <= high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    return low;
}
int partition_median_of_three(int arr[], int p, int r) {
    int mid = p + (r - p) / 2;
    int a = arr[p];
    int b = arr[mid];
    int c = arr[r];
    int pivot = max(min(a, b), min(max(a, b), c));

    int low = p;
    int high = r;

    while (low <= high) {
        while (arr[low] < pivot) low++;
        while (arr[high] > pivot) high--;

        if (low <= high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    return low;
}


void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);

        quick_sort(arr, left, pivot - 1); // 피벗을 기준으로 왼쪽 배열 정렬
        quick_sort(arr, pivot + 1, right); // 피벗 기준으로 오른쪽 배열 정렬
    }
}
void quick_sort_1(int arr[], int left, int right) {
    stack<int> stk;
    stk.push(left);
    stk.push(right);

    while (!stk.empty()) {
        int r = stk.top();
        stk.pop();
        int p = stk.top();
        stk.pop();

        if (p < r) {
            int pivot = partition(arr, p, r);
            stk.push(p);
            stk.push(pivot - 1);
            stk.push(pivot + 1);
            stk.push(r);
        }
    }
}
void quick_sort_2(int arr[], int left, int right) {
    stack<int> stk;
    stk.push(left);
    stk.push(right);

    while (!stk.empty()) {
        int r = stk.top();
        stk.pop();
        int p = stk.top();
        stk.pop();
        if (r - p + 1 <= 10) {
            insertion_sort(arr, p, r);
        }
        else {
            if (p < r) {
                int pivot = partition(arr, p, r);
                stk.push(p);
                stk.push(pivot - 1);
                stk.push(pivot + 1);
                stk.push(r);
            }
        }
    }
}
void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = { 3, 2, 1, 5, 7, 9, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
