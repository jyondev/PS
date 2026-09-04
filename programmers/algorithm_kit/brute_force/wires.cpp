// Level 2, 전력망을 둘로 나누기
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void traversal(int& cur, int& exception, vector<bool>& visited, vector<vector<int>>& connection, int& count) {
    for (int i : connection[cur]) {
        if (i == exception) continue;
        if (!visited[i]) {
            ++count;
            visited[i] = true;
            traversal(i, exception ,visited, connection, count);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    vector<vector<int>> connection(n+1);
    for (vector<int> v : wires) {
        connection[v[0]].push_back(v[1]);
        connection[v[1]].push_back(v[0]);
    }
    for (vector<int>& v : wires) {
        vector<bool> visited(n+1, false);
        visited[v[0]] = true; visited[v[1]] = true;
        int count1 = 1; int count2 = 1;
        traversal(v[0], v[1], visited, connection, count1);
        traversal(v[1], v[0], visited, connection, count2);
        if (answer > abs(count1-count2)) {
            answer = abs(count1-count2);
        }
    }
    return answer;
}