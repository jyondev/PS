// DFS, [Gold 5], Time Limit: 1sec
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<char>>& picture, vector<vector<bool>>& visited,
    pair<int, int> cur) {
        visited[cur.first][cur.second] = true;
        char color = picture[cur.first][cur.second];
        int move_row[4] = {0,1,0,-1};
        int move_column[4] = {1,0,-1,0};
        for (int i = 0; i < 4; ++i) {
            int row = cur.first + move_row[i];
            int column = cur.second + move_column[i];
            if (row >= 0 && row < picture.size() &&
            column >= 0 && column < picture[0].size()) {
                if (!visited[row][column] && picture[row][column] == color) {
                    DFS(picture, visited, {row, column});
                }
            }
        }
}

int main() {
    int N; cin >> N;
    vector<vector<char>> picture1(N, vector<char>(N, 'R'));
    vector<vector<char>> picture2(N, vector<char>(N, 'R'));
    vector<vector<bool>> visited1(N, vector<bool>(N, false));
    vector<vector<bool>> visited2(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        for (int j = 0; j < N; ++j) {
            picture1[i][j] = s[j];
            if (s[j] == 'G') {
                picture2[i][j] = 'R';
            } else {
                picture2[i][j] = s[j];
            }
        }
    }

    int area1 = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited1[i][j]) {
                ++area1;
                DFS(picture1,visited1,{i, j});
            }
        }
    }    
    int area2 = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited2[i][j]) {
                ++area2;
                DFS(picture2,visited2,{i, j});
            }
        }
    }

    cout << area1 << " " << area2;
}