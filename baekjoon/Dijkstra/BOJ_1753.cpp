// Dijkstra, [Gold 4], Time Limit: 1sec
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

void Dijkstra(vector<vector<pair<int,int>>>& connection, vector<int>& distance,
    int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>> next;
        // priority_queue<자료형, 저장소, 정렬방식>
        next.push({0, start}); distance[start] = 0;
        while (!next.empty()) {
            int cost = next.top().first;
            int node = next.top().second;
            next.pop();

            if (distance[node] < cost) continue;
            else {
                for (pair<int, int>& p : connection[node]) {
                    if (distance[p.first] > cost + p.second) {
                        next.push({cost+p.second, p.first});
                        distance[p.first] = cost+p.second;
                    }
                }
            }
        }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int V,E,K; cin >> V >> E >> K;
    vector<vector<pair<int,int>>> connection(V+1);
    vector<int> distance(V+1, INT_MAX);
    for (int i = 0; i < E; ++i) {
        int u,v,w; cin >> u >> v >> w;
        connection[u].push_back({v,w});
    }
    Dijkstra(connection, distance, K);
    for (int i = 1; i <= V; ++i) {
        if (distance[i] == INT_MAX) {
            cout << "INF" << '\n';
            continue;
        }
        cout << distance[i] << '\n';
    }
}