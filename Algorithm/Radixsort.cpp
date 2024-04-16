#include <iostream>
#include <queue>
using namespace std;
X`
const int MAX = 10; // �迭�� �ִ� ũ��
const int Max_Value = 1000; // �迭 ����� �ִ� ��

int Arr[MAX]; // ������ �迭
queue<int> Q[MAX]; // ť �迭

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
    srand((unsigned)time(NULL)); // ���� �õ� ����

    // �迭 �ʱ�ȭ
    for (int i = 0; i < MAX; ) {
        Arr[i] = (rand() % 10000) + 1; // 1���� 10000������ ���� ����
        if (!Flag[Arr[i]]) {
            Flag[Arr[i]] = true;
            i++;
        }
    }

    cout << "[ Initialize Array State ] " << endl;
    Print(); // �迭 �ʱ� ���� ���

    Radix_Sort(); // Radix Sort ����

    cout << "[ After Sort Array State ] " << endl;
    Print(); // ���� �� �迭 ���� ���

    return 0;
}