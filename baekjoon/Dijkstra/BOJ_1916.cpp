// Dijkstra, [Gold 5], Time Limit: 0.5sec
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(vector<int>& city, vector<vector<pair<int,int>>>& bus, int start, int end) {
    priority_queue<
    pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> next;
    next.push({0, start});
    while (!next.empty()) {
        pair<int, int> t = next.top(); next.pop();
        int cost = t.first;
        int dest = t.second;
        if (cost > city[dest]) continue;
        else {
            city[dest] = cost;
            for (pair<int,int> p : bus[dest]) {
                if (cost + p.second < city[p.first]) {
                    city[p.first] = cost + p.second;
                    next.push({city[p.first], p.first});
                }
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int N,M; cin >> N >> M;
    vector<vector<pair<int,int>>> bus(N+1);
    vector<int> city(N+1, INT_MAX);

    for (int i = 0; i < M; ++i) {
        int a,b,c; cin >> a >> b >> c;
        bus[a].push_back({b,c});
    }

    int start,end; cin >> start >> end;

    Dijkstra(city,bus,start,end);
    cout << city[end];
}