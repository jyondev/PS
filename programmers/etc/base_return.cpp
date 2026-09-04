// Level 3, 부대복귀
// Dijkstra
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Dijkstra(vector<vector<int>>& connected, vector<int>& distance, int& start, int& destination) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; pq.push({0,start});
    while (!pq.empty()) {
        pair<int,int> t = pq.top(); pq.pop();
        for (int& i : connected[t.second]) {
            if (distance[i] > t.first + 1) {
                distance[i] = t.first+1;
                if (i != destination) {
                    pq.push({t.first+1,i});
                }
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> connected(n+1);
    for (vector<int>& v : roads) {
        connected[v[0]].push_back(v[1]);
        connected[v[1]].push_back(v[0]);
    }
    for (int i = 0; i < sources.size(); ++i) {
        int start = sources[i];
        if (start == destination) {
            answer.push_back(0);
            continue;
        }
        vector<int> distance(n+1, 100001);
        Dijkstra(connected,distance,start,destination);
        if (distance[destination] == 100001) {
            distance[destination] = -1;
        }
        answer.push_back(distance[destination]);
    }
    return answer;
}