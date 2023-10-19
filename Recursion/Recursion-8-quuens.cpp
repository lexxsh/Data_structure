#include<iostream>
#include<cmath>

using namespace std;
const int N = 8;
int queensInRow[N];
int cnt = 0;

void printQueens() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (queensInRow[i] == j) {
                cout << "Q ";
            }
            else {
                cout << "x ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cnt++;
}

bool check(int k, int i) {
    for (int j = 0; j < k; j++)
        if ((queensInRow[j] == i) || (abs(queensInRow[j] - i) == abs(j - k)))
            return false;
    return true;
}
void solve(int k) {
    if (k == N) {
        printQueens();
    }
    else {
        for (int i = 0; i < N; i++) {
            if (check(k, i)) {
                queensInRow[k] = i;
                solve(k + 1);
            }
        }
    }
}
int main() {
    solve(0);
    cout << "ÃÑ °¡´ÉÇÑ ¼ö : " << cnt << endl;
    return 0;
}