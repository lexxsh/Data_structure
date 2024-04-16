#include <iostream>
#include <queue>
using namespace std;
X`
const int MAX = 10; // 배열의 최대 크기
const int Max_Value = 1000; // 배열 요소의 최대 값

int Arr[MAX]; // 정렬할 배열
queue<int> Q[MAX]; // 큐 배열

void Radix_Sort() {
    int Radix = 1;
    while (1) {
        if (Radix >= Max_Value) break;
        Radix = Radix * 10;
    }

    for (int i = 1; i < Radix; i = i * 10) {
        for (int j = 0; j < MAX; j++) {
            int K;
            if (Arr[j] < i) K = 0;
            else K = (Arr[j] / i) % 10;
            Q[K].push(Arr[j]);
        }

        int Idx = 0;
        for (int j = 0; j < 10; j++) {
            while (!Q[j].empty()) {
                Arr[Idx] = Q[j].front();
                Q[j].pop();
                Idx++;
            }
        }
    }
}

int main(void) {
    srand((unsigned)time(NULL)); // 난수 시드 설정

    // 배열 초기화
    for (int i = 0; i < MAX; ) {
        Arr[i] = (rand() % 10000) + 1; // 1부터 10000까지의 난수 생성
        if (!Flag[Arr[i]]) {
            Flag[Arr[i]] = true;
            i++;
        }
    }

    cout << "[ Initialize Array State ] " << endl;
    Print(); // 배열 초기 상태 출력

    Radix_Sort(); // Radix Sort 수행

    cout << "[ After Sort Array State ] " << endl;
    Print(); // 정렬 후 배열 상태 출력

    return 0;
}