// DFS + Backtracking, [Gold 4], Time Limit: 2sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(vector<vector<char>>& board, pair<int, int> cur,
    vector<bool>& visited, int& count, int& max) {
        if (count > max) {max = count;}
        int move_row[4] = {0,1,0,-1};
        int move_column[4] = {1,0,-1,0};

        for (int i = 0; i < 4; ++i) {
            int row = cur.first + move_row[i];
            int column = cur.second + move_column[i];
            if (row >= 0 && row < board.size() &&
                column >= 0 && column < board[0].size()) {
                    if (!visited[board[row][column] - 'A']) {
                        visited[board[row][column] - 'A'] = true;
                        ++count;
                        DFS(board, {row, column}, visited, count, max);
                        visited[board[row][column]-'A'] = false;
                        --count;
                    }
            }
        }
}


int main() {
    int R, C; cin >> R >> C;
    vector<vector<char>> board(R);
    vector<bool> visited(26, false);
    for (int i = 0; i < R; ++i) {
        string s; cin >> s;
        for (int j = 0; j < C; ++j) {
            board[i].push_back(s[j]);
        }
    }
    visited[board[0][0]-'A'] = true;

    int count = 1; int max = 0;
    DFS(board, {0,0}, visited, count, max);
    cout << max;
}