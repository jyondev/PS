// BFS + Backtracking + Simulation, [Gold 4], Time Limit: 2sec
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int countSafeArea(vector<vector<int>>& lab) {
    int count = 0;
    for (int i = 0; i < lab.size(); ++i) {
        for (int j = 0; j < lab[0].size(); ++j) {
            if (lab[i][j] == 0) {
                ++count;
            }
        }
    }
    return count;
}

void spreadVirus(vector<vector<int>>& lab, queue<pair<int, int>>& cur) {
    int d_row[4] = {0,1,0,-1};
    int d_column[4] = {1,0,-1,0};
    while (!cur.empty()) {
        pair<int, int> f = cur.front(); cur.pop();
        for (int i = 0; i < 4; ++i) {
            int row = f.first + d_row[i];
            int column = f.second + d_column[i];
            if (row >= 0 && row < lab.size() && column >= 0
                && column < lab[0].size()) {
                    if (lab[row][column] == 0) {
                        cur.push({row, column});
                        lab[row][column] = 2;
                    }
            }
        }
    }
}

void buildWall(vector<vector<int>>& lab, queue<pair<int, int>>& cur,
        int& w_count, int& max) {
    if (w_count == 3) {
        vector<vector<int>> l = lab;
        queue<pair<int, int>> c = cur;
        spreadVirus(l, c);
        int safe = countSafeArea(l);
        if (safe > max) {max = safe;}
        return;
    }
    for (int i = 0; i < lab.size(); ++i) {
        for (int j = 0; j < lab[0].size(); ++j) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                ++w_count;
                buildWall(lab, cur, w_count, max);
                lab[i][j] = 0;
                --w_count;
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> lab(N);
    queue<pair<int, int>> virus;
    int w_count = 0; int max = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int n; cin >> n;
            if (n == 2) {
                virus.push({i,j});
            }
            lab[i].push_back(n);
        }
    }
    buildWall(lab, virus, w_count, max);
    cout << max;
}