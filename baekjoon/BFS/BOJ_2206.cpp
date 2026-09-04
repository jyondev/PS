// BFS, [Gold 3], Time Limit: 2sec
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> road[2], queue<pair<bool, pair<int,int>>>& next) {
    queue<pair<bool, pair<int, int>>> n;

    int move_row[4] = {0,1,0,-1};
    int move_column[4] = {1,0,-1,0};

    while (!next.empty()) {
        pair<bool, pair<int, int>> f = next.front(); next.pop();
        for (int i = 0; i < 4; ++i) {
            int row = f.second.first + move_row[i];
            int column = f.second.second + move_column[i];
            if (row >= 0 && row < road[0].size() && column >= 0 && column < road[0][0].size()) {
                if (f.first) {
                    if (road[0][row][column] == 1) {
                        n.push({false,{row,column}});
                        road[1][row][column] = 1;
                    } else {
                        n.push({true, {row,column}});
                        road[0][row][column] = 1;
                    }
                } else {
                    if (road[1][row][column] == 1) continue;
                    else {
                        road[1][row][column] = 1;
                        n.push({false,{row,column}});
                    }
                }
            }
        }
    }

    next.swap(n);
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> road[2]; // road[0]: 벽 안부숨 road[1]: 벽 부숨
    road[0] = vector<vector<int>>(N);
    queue<pair<bool, pair<int, int>>> next; // 벽 안부숨 == true, {좌표}
    next.push({true, {0,0}});

    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        for (int j = 0; j < M; ++j) {
            road[0][i].push_back(s[j]-'0');
        }
    }
    road[0][0][0] = 1;
    road[1] = road[0];

    int distance = 1;
    while (!next.empty()) {
        if (road[0][N-1][M-1] || road[1][N-1][M-1]) break;
        ++distance;
        BFS(road, next);
    }
    if (road[0][N-1][M-1] == 0 && road[1][N-1][M-1] == 0) {
        cout << -1; return 0;
    }
    cout << distance;
}