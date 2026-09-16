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

// #include <string>
// #include <vector>
// #include <set>

// using namespace std;

// int solution(int n, vector<vector<int>> computers) {
//     vector<int> leader;
//     for (int i = 0; i < n; ++i) {
//         leader.push_back(i);
//     }
//     for (int k = 0; k < n; ++k) {
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (computers[i][k] && computers[k][j]) {
//                     computers[i][j] = 1;
//                 }
//             }
//         }
//     }
    
//     set<int> s;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             if (computers[i][j]) {
//                 s.insert(j);
//                 break;
//             }
//         }
//     }
//     return s.size();
// }