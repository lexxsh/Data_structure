#include <iostream>
#include <queue>
#include<stack>
using namespace std;

const int MAX_NODES = 8;

void BFS(int graph[MAX_NODES][MAX_NODES], int start) {
    bool visited[MAX_NODES] = { false };

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int i = 0; i < MAX_NODES; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
void DFS(int graph[MAX_NODES][MAX_NODES], int start) {
    bool visited[MAX_NODES] = { false }; // 방문 여부를 저장하는 배열

    stack<int> s; // 스택을 이용한 구현
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            // 인접 노드 스택에 삽입 (역순으로)
            for (int i = MAX_NODES - 1; i >= 0; --i) {
                if (graph[current][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
}
int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        { 0, 1, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 0, 1, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 0, 0, 0, 1, 0, 1, 0 }
    };

    BFS(graph, 0);
    cout << endl;
    DFS(graph, 0);
    return 0;
}
