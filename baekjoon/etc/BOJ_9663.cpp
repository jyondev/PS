// Backtracking, [Gold 4], Time Limit: 10sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(int row, vector<bool> column, vector<bool> diagonal1,
    vector<bool> diagonal2, int& count) {
    if (row == column.size()) {
        ++count; return;
    }
    for (int j = 0; j < column.size(); ++j) {
        if (column[j] && diagonal1[row+j] && diagonal2[row-j+column.size()-1]) {
            column[j] = false;
            diagonal1[row+j] = false;
            diagonal2[row-j+column.size()-1] = false;
            backtrack(row+1, column, diagonal1, diagonal2, count);
            column[j] = true;
            diagonal1[row+j] = true;
            diagonal2[row-j+column.size()-1] = true;
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<bool> column(N, true);
    vector<bool> diagonal1(2*N, true); // 우상향 대각선, i+j가 같음
    vector<bool> diagonal2(2*N, true); // 좌상향 대각선, i-j가 같음
    int count = 0;
    backtrack(0,column,diagonal1,diagonal2,count);
    cout << count;
}