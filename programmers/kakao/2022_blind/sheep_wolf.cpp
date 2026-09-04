// Level 3, 양과 늑대
// DFS
// 다른 브랜치로 접근하기 위해 next_nodes를 활용하여 재귀
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void backTrackDFS(vector<int>& info, vector<vector<int>>& connection, vector<int> next_nodes, pair<int,int> count, int& answer, int cur) {
    if (info[cur] == 0) ++count.first;
    else ++count.second;
    
    if (count.first <= count.second) return;
    if (answer < count.first) answer = count.first;
    
    vector<int> next;
    for (int& i : next_nodes) {
        if (i == cur) continue;
        next.push_back(i);
    }
    for (int& i : connection[cur]) {
        next.push_back(i);
    }
    
    for (int& i : next) {
        backTrackDFS(info, connection, next, count, answer, i);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> connection(info.size());
    for (vector<int>& v : edges) {
        connection[v[0]].push_back(v[1]);
    }
    backTrackDFS(info,connection,{},{0,0},answer,0);
    return answer;
}