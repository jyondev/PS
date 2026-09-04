// Tree + BFS, [Silver 2], Time Limit: 1sec
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& connection, vector<int>& parent, vector<bool>& visited) {
    queue<int> q; q.push(1); visited[1] = true;
    while (!q.empty()) {
        int f = q.front(); q.pop();
        vector<int> v = connection[f];
        for (int i : v) {
            if (!visited[i]) {
                parent[i] = f;
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int N; cin >> N;
    vector<int> parent(N+1, 0); parent[1] = 1;
    vector<bool> visited(N+1, false);
    vector<vector<int>> connection(N+1);
    
    for (int i = 1; i < N; ++i) {
        int n1, n2; cin >> n1 >> n2;
        connection[n1].push_back(n2);
        connection[n2].push_back(n1);
    }

    BFS(connection, parent, visited);

    for (int i = 2; i < parent.size(); ++i) {
        cout << parent[i] << '\n';
    }
}