// Level 3, 합승 택시 요금
// Dijkstra, Floyd 모두 풀이 가능
#include <string>
#include <vector>
#include <queue>

using namespace std;

void Floyd(vector<vector<int>>& fee) {
    int n = fee.size()-1;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (fee[i][j] > fee[i][k] + fee[k][j]) {
                    fee[i][j] = fee[i][k]+fee[k][j];
                    fee[j][i] = fee[i][k]+fee[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> fee(n+1,vector<int>(n+1,200000000));
    for (vector<int>& v : fares) {
        fee[v[0]][v[1]] = v[2];
        fee[v[1]][v[0]] = v[2];
    }
    for (int i = 1; i <= n; ++i) {
        fee[i][i] = 0;
    }
    Floyd(fee);
    int answer = fee[s][a]+fee[s][b];
    for (int i = 1; i <= n; ++i) {
        if (fee[s][i]+fee[i][a]+fee[i][b] < answer) {
            answer = fee[s][i]+fee[i][a]+fee[i][b];
        }
    }
    return answer;
}