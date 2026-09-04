// BFS, [Gold 5], Time Limit: 1sec
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
    int height, row, column;
    Pos(int h, int r, int c) {
        this->height = h;
        this->row = r;
        this->column = c;
    }
};

bool BFS(vector<vector<vector<int>>>& tomato, queue<Pos>& riped, queue<Pos>& next) {
    if (riped.empty()) return true;
    int move_height[6] = {0,0,0,0,1,-1};
    int move_row[6] = {0,1,0,-1,0,0};
    int move_column[6] = {1,0,-1,0,0,0};
    while (!riped.empty()) {
        Pos p = riped.front(); riped.pop();
        for (int i = 0; i < 6; ++i) {
            int height = p.height + move_height[i];
            int row = p.row + move_row[i];
            int column = p.column + move_column[i];
            if (height >= 0 && height < tomato.size() && row >= 0 && row < tomato[0].size()
            && column >= 0 && column < tomato[0][0].size()) {
                if (tomato[height][row][column] == 0) {
                    tomato[height][row][column] = 1;
                    next.push(Pos(height,row,column));
                }
            }
        }
    }
    riped.swap(next);
    next = {};
    return false;
}

int main() {
    int M,N,H; cin >> M >> N >> H;
    vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M,0)));
    bool allRiped = true;
    queue<Pos> riped; queue<Pos> next;
    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                int val; cin >> val;
                tomato[h][r][c] = val;
                if (val == 1) {
                    riped.push(Pos(h,r,c));
                }
                if (val == 0) {
                    allRiped = false;
                }
            }
        }
    }
    if (allRiped) {
        cout << 0; return 0;
    }

    int day = -1;
    while (!BFS(tomato, riped, next)) {
        ++day;
    }

    for (int h = 0; h < H; ++h) {
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (tomato[h][r][c] == 0) {
                    cout << -1; return 0;
                }
            }
        }
    }

    cout << day;
}