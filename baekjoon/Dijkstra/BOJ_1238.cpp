// Dijkstra, [Gold 3], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(vector<vector<pair<int,int>>>& go, vector<vector<pair<int,int>>>& back,
    vector<int>& result, int cur) {
        vector<int> time1(go.size(), INT_MAX); // 돌아올 때
        vector<int> time2(go.size(), INT_MAX); // 파티 갈 때
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>
        next;
    next.push({0, cur}); time1[cur] = 0;
    while (!next.empty()) {
        int time = next.top().first;
        int village = next.top().second;
        next.pop();
        if (time1[village] < time) continue;
        else {
            time1[village] = time;
            for (pair<int, int>& p : back[village]) {
                if (time1[p.first] > time + p.second) {
                    time1[p.first] = time + p.second;
                    next.push({time + p.second, p.first});
                }
            }
        }
    }

    next.push({0, cur}); time2[cur] = 0;
    while (!next.empty()) {
        int time = next.top().first;
        int village = next.top().second;
        next.pop();
        if (time2[village] < time) continue;
        else {
            time2[village] = time;
            for (pair<int, int>& p : go[village]) {
                if (time2[p.first] > time + p.second) {
                    time2[p.first] = time + p.second;
                    next.push({time + p.second, p.first});
                }
            }
        }
    }

    for (int i = 1; i < go.size(); ++i) {
        result[i] = time1[i] + time2[i];
    }
    sort(result.begin(), result.end());
}

int main() {
    int N,M,X; cin >> N >> M >> X;
    vector<vector<pair<int, int>>> go(N+1);
    vector<vector<pair<int, int>>> back(N+1);
    vector<int> result(N+1);

    for (int i = 0; i < M; ++i) {
        int start, end, time; cin >> start >> end >> time;
        go[start].push_back({end, time});
        back[end].push_back({start, time});
    }

    Dijkstra(go, back, result, X);
    cout << result[N];
}