// BFS, [Silver 1], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    int maze[N][M];
    for (int i = 0; i < N; ++i) {
        string line; cin >> line;
        for (int j = 0; j < M; ++j) {
            maze[i][j] = line[j] - '0';
        }
    }

    int move_x[4] = {1,0,-1,0};
    int move_y[4] = {0,1,0,-1};
    queue<pair<int,int>> q; q.push({0,0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int row = cur.first + move_x[i];
            int column = cur.second + move_y[i];
            int count = maze[cur.first][cur.second] + 1;
            if (row >= 0 && row < N && column >= 0 && column < M) {
                if (maze[row][column] == 0) {
                    continue;
                }
                else {
                    if (count < maze[row][column] || maze[row][column] == 1) {
                        maze[row][column] = count;
                        q.push({row, column});
                    }
                }
            }
        }

        if (maze[N-1][M-1] != 1) {
            cout << maze[N-1][M-1]; return 0;
        }
    }
}