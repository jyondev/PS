// BFS, [Gold 5], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& tomato, queue<pair<int, int>>& riped, int& day) {
    if (riped.empty()) return;
    ++day;
    int move_row[4] = {0,1,0,-1};
    int move_column[4] = {1,0,-1,0};
    queue<pair<int, int>> new_riped;

    while (!riped.empty()) {
        pair<int, int> f = riped.front(); riped.pop();
        for (int i = 0; i < 4; ++i) {
            int row = f.first + move_row[i];
            int column = f.second + move_column[i];
            if (row >= 0 && row < tomato.size() && column >= 0 
                && column < tomato[0].size()) {
                    if (tomato[row][column] == 0) {
                        new_riped.push({row, column});
                        tomato[row][column] = 1;
                    }
            }
        }
    }
    riped = new_riped;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, N; cin >> M >> N;
    vector<vector<int>> tomato(N, vector<int>(M, 0));
    queue<pair<int, int>> riped;
    vector<pair<int, int>> notRiped;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int val; cin >> val;
            if (val == 0) {
                notRiped.push_back({i, j});
            } else if (val == 1) {
                riped.push({i, j});
            }
            tomato[i][j] = val;
        }
    }

    if (notRiped.empty()) {
        cout << 0; return 0;
    }

    int day = -1;
    while (!riped.empty()) {
        BFS(tomato, riped, day);
    }
    for (vector<int> v: tomato) {
        for (int i : v) {
            if (i == 0) {cout << -1; return 0;}
        }
    }

    cout << day;
}