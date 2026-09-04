// Level 3, 등산코스 정하기
// Dijkstra
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Dijkstra(vector<vector<pair<int,int>>>& connection, vector<int>& intensity, vector<int>& gates, vector<int>& summits) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int& i : gates) {
        pq.push({0,i});
    }
    while (!pq.empty()) {
        pair<int,int> t = pq.top(); pq.pop();
        for (pair<int,int>& p : connection[t.second]) {
            int stan = max(t.first, p.first);
            if (stan < intensity[p.second]) {
                intensity[p.second] = stan;
                if (find(summits.begin(),summits.end(),p.second) == summits.end()) {
                    pq.push({stan,p.second});
                }
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> intensity(n+1,10000001);
    vector<vector<pair<int,int>>> connection(n+1);
    for (vector<int>& v : paths) {
        connection[v[0]].push_back({v[2],v[1]});
        connection[v[1]].push_back({v[2],v[0]});
    }
    Dijkstra(connection,intensity,gates,summits);
    vector<int> answer = {50001, 10000001};
    for (int& i : summits) {
        if (intensity[i] == answer[1]) {
            answer[0] = min(answer[0], i);
        }
        if (intensity[i] < answer[1]) {
            answer[0] = i; answer[1] = intensity[i];
        }
    }
    return answer;
}