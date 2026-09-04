// Level 2, 배달
// Dijkstra 기본문제

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Dijkstra(vector<vector<pair<int,int>>>& connection, vector<int>& distance) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    while (!pq.empty()) {
        pair<int,int> t = pq.top(); pq.pop();
        for (pair<int,int>& p : connection[t.second]) {
            if (distance[p.second] > t.first + p.first) {
                pq.push({t.first+p.first, p.second});
                distance[p.second] = t.first+p.first;
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<pair<int,int>>> connection(N+1); // {출발,{비용,도착}}
    vector<int> distance(N+1, 200000000); distance[1] = 0;
    for (vector<int>& v : road) {
        connection[v[0]].push_back({v[2],v[1]});
        connection[v[1]].push_back({v[2],v[0]});
    }
    Dijkstra(connection,distance);
    for (int& i : distance) {
        if (i <= K) ++answer;
    }
    return answer;
}