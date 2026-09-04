// BFS, [Silver 1], Time Limit: 2sec
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(vector<int>& visited, queue<int>& pos, queue<int>& pos1, int K) {
    while (!pos.empty()) {
        int p = pos.front(); pos.pop();
        if (p == K) return true;
        int p1 = p-1;
        int p2 = p+1;
        int p3 = 2*p;
        if (p1 >= 0 && p1 <= 100000) {
            if (!visited[p1]) {
                pos1.push(p1);
                visited[p1] = visited[p] + 1;
            }
        }
        if (p2 >= 0 && p2 <= 100000) {
            if (!visited[p2]) {
                pos1.push(p2);
                visited[p2] = visited[p] + 1;
            }
        }
        if (p3 >= 0 && p3 <= 100000) {
            if (!visited[p3]) {
                pos1.push(p3);
                visited[p3] = visited[p] + 1;
            }
        }
    }

    pos.swap(pos1);
    return false;
}

int main() {
    int N, K; cin >> N >> K;
    vector<int> visited(100001, 0);
    queue<int> pos; pos.push(N);
    queue<int> pos1;
    while (!BFS(visited, pos, pos1, K)) {}
    cout << visited[K];
}