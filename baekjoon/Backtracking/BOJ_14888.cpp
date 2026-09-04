// Backtracking, [Silver 1], Time Limit: 2sec
#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> num, int oper[4], int result[2], int idx, int cur) {
    if (idx == num.size()) {
        if (cur > result[0]) {
            result[0] = cur;
        }
        if (cur < result[1]) {
            result[1] = cur;
        }
        return;
    }
    if (oper[0] > 0) {
        --oper[0];
        backtrack(num, oper, result, idx+1, cur + num[idx]);
        ++oper[0];
    }
    if (oper[1] > 0) {
        --oper[1];
        backtrack(num, oper, result, idx+1, cur - num[idx]);
        ++oper[1];
    }
    if (oper[2] > 0) {
        --oper[2];
        backtrack(num, oper, result, idx+1, cur * num[idx]);
        ++oper[2];
    }
    if (oper[3] > 0) {
        --oper[3];
        backtrack(num, oper, result, idx+1, cur / num[idx]);
        ++oper[3];
    }
}

int main() {
    int N; cin >> N;
    vector<int> num(N);
    int oper[4];
    int result[2] = {-1000000001, 1000000001}; // 0: max 1: min

    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> oper[i];
    }

    backtrack(num, oper, result, 1, num[0]);
    cout << result[0] << '\n';
    cout << result[1] << '\n';
}