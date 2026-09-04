// Level 3, 퍼즐 조각 채우기
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void rotate(vector<pair<int,int>>& v, int N) {
    for (pair<int,int>& p : v) {
        int r = p.first;
        p.first = p.second;
        p.second = N-1-r;
    }
    int min_row = N; int min_column = N;
    for (pair<int,int>& p : v) {
        if (p.first < min_row) min_row = p.first;
        if (p.second < min_column) min_column = p.second;
    }
    for (pair<int,int>& p : v) {
        p.first -= min_row;
        p.second -= min_column;
    }
    sort(v.begin(),v.end());
}

vector<vector<pair<int,int>>> getPieces(vector<vector<int>>& board, int k) {
    vector<vector<pair<int,int>>> gP;
    int move_row[4] = {0,1,0,-1};
    int move_column[4] = {1,0,-1,0};
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] != k) {
                queue<pair<int,int>> q; q.push({i,j});
                board[i][j] = k;
                vector<pair<int,int>> v;
                while (!q.empty()) {
                    pair<int,int> p = q.front(); q.pop();
                    v.push_back(p);
                    for (int r = 0; r < 4; ++r) {
                        int row = p.first+move_row[r];
                        int column = p.second+move_column[r];
                        if (row < 0 || row >= board.size() || column < 0 || column >= board.size()) continue;
                        if (board[row][column] != k) {
                            board[row][column] = k;
                            q.push({row,column});
                        }
                    }
                }
                int min_row = board.size(); int min_column = board.size();
                for (pair<int,int>& p : v) {
                    if (p.first < min_row) min_row = p.first;
                    if (p.second < min_column) min_column = p.second;
                }
                for (pair<int,int>& p : v) {
                    p.first -= min_row;
                    p.second -= min_column;
                }
                sort(v.begin(),v.end());
                gP.push_back(v);
            }
        }
    }
    return gP;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int,int>>> board_pieces = getPieces(game_board, 1);
    vector<vector<pair<int,int>>> table_pieces = getPieces(table,0);
    vector<bool> used(table_pieces.size(),false);
    for (vector<pair<int,int>> v1 : board_pieces) {
        bool matched = false;
        for (int k = 0; k < table_pieces.size(); ++k) {
            if (used[k]) continue;
            for (int i = 0; i < 4; ++i) {
                if (v1 == table_pieces[k]) {
                    answer += v1.size();
                    matched = true;
                    used[k] = true;
                    break;
                }
                rotate(table_pieces[k], table.size());
            }
            if (matched) break;
        }
    }
    return answer;
}