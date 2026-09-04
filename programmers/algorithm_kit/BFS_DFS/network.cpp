// Level 3, 네트워크
#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>>& computers, vector<bool>& visited, int cur) {
    visited[cur] = true;
    for (int i = 0; i < computers[cur].size(); ++i) {
        if (i != cur && computers[cur][i] == 1 && !visited[i]) {
            DFS(computers,visited,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(computers, visited, i);
            ++answer;
        }
    }
    return answer;
}