// DFS & BFS, [Silver 2], Time Limit: 2sec
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(vector<int>* graph, bool* visited, int startIdx) {
    visited[startIdx] = true;
    cout << startIdx << " ";

    for (int i : graph[startIdx]) {
        if (!visited[i]) {
            DFS(graph, visited, i);
        }
    }
}
void BFS(vector<int>* graph, bool* visited, int startIdx) {
    queue<int> q;

    q.push(startIdx);
    visited[startIdx] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        cout << s << " ";

        vector<int> g = graph[s];

        for (int i : graph[s]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int N, M, V; cin >> N >> M >> V;
    vector<int> graph[1001];
    bool visited1[1001];
    bool visited2[1001];
    fill(visited1, visited1 + 1001, false);
    fill(visited2, visited2 + 1001, false);

    for (int i = 0; i < M; ++i) { // O(M)
        int n1, n2; cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for (int i = 1; i < 1001; ++i) { // O(NlogN)
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(graph, visited1, V);
    cout << "\n";
    BFS(graph, visited2, V);
}