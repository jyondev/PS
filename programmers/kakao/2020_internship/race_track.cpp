// Level 3, 경주로 건설
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector<vector<vector<int>>>& v, vector<vector<int>>& board) {
    int move_row[4] = {0,1,0,-1};
    int move_column[4] = {1,0,-1,0};
    queue<vector<int>> q; // {row,column,direction}
    q.push({0,0,0}); q.push({0,0,1});
    while (!q.empty()) {
        vector<int> f = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int row = f[0]+move_row[i];
            int column = f[1]+move_column[i];
            if (row >= 0 && row < board.size() && column >= 0 && column < board.size() && board[row][column] != -1) {
                int t = 1;
                if (i != f[2]) {t+=5;}
                if (v[row][column][i] == 0 || v[row][column][i] > v[f[0]][f[1]][f[2]] + t) {
                    v[row][column][i] = v[f[0]][f[1]][f[2]] + t;
                    q.push({row,column,i});
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] == 1) board[i][j] = -1;
        }
    }
    vector<vector<vector<int>>> v(board.size(),vector<vector<int>>(board.size(),vector<int>(4,0))); 
    // {row,column,direction}
    BFS(v,board);
    if (v[board.size()-1][board.size()-1][0] == 0) {
        return v[board.size()-1][board.size()-1][1]*100;
    } else if (v[board.size()-1][board.size()-1][1] == 0) {
        return v[board.size()-1][board.size()-1][0]*100;
    } else {
        return min(v[board.size()-1][board.size()-1][0],v[board.size()-1][board.size()-1][1]) * 100;
    }
}