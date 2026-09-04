// Level 3, 여행경로
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool DFS(vector<string>& answer, map<string,vector<string>>& m,
        map<string,vector<bool>>& visited, string cur, int size) {
    if (answer.size() == size + 1) return true;
    for (int i = 0; i < m[cur].size(); ++i) {
        if (!visited[cur][i]) {
            visited[cur][i] = true;
            answer.push_back(m[cur][i]);
            if (DFS(answer,m,visited,m[cur][i],size)) {
                return true;
            }
            visited[cur][i] = false;
            answer.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer; answer.push_back("ICN");
    map<string,vector<string>> m;
    map<string,vector<bool>> visited;
    for (vector<string> v : tickets) {
        m[v[0]].push_back(v[1]);
        visited[v[0]].push_back(false);
    }
    for (pair<string, vector<string>> p : m) {
        sort(m[p.first].begin(), m[p.first].end());
    }
    DFS(answer,m,visited,"ICN",tickets.size());
    return answer;
}