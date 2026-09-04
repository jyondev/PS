// Queue, [Silver 3], Time Limit: 2sec
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, M; cin >> N >> M;
        queue<pair<int, int>> q; // {idx, imp}
        priority_queue<int> p;
        
        int count = 1;

        for (int a = 0; a < N; ++a) {
            int imp; cin >> imp;
            q.push({a, imp});
            p.push(imp);
        }

        while (!q.empty()) {
            int first = q.front().first;
            int second = q.front().second;

            if (second == p.top()) {
                if (first == M) break;
                ++count; q.pop(); p.pop();
            } else {
                q.push({first, second});
                q.pop();
            }
        }

        cout << count << '\n';
    }
}