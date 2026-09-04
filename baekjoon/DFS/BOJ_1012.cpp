// DFS, [Silver 2], Time Limit: 1sec
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<int>>& field, pair<int, int> cur) {
    field[cur.first][cur.second] = 0;
    int move_row[4] = {1,0,-1,0};
    int move_column[4] = {0,1,0,-1};

    for (int i = 0; i < 4; ++i) {
        int row = cur.first + move_row[i];
        int column = cur.second + move_column[i];

        if (row >= 0 && row < field.size() && column >= 0 && column < field[0].size()) {
            if (field[row][column]) {
                DFS(field, {row, column});
            }
        }
    }
}



int main() {
    int T; cin >> T;
    while (T--) {
        int M,N,K; cin >> M >> N >> K;
        vector<vector<int>> field(N, vector<int>(M,0)); // Initialize

        int X,Y;

        for (int j = 0; j < K; ++j) {
            cin >> X >> Y;
            field[Y][X] = 1;
        }

        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (field[i][j]) {
                    ++count;
                    DFS(field, {i, j});
                }
            }
        }
        cout << count << '\n';
    }
}