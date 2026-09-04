// DP, [Silver 3], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> val(N);
    vector<int> score(N);
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }
    score[0] = val[0];
    if (N > 1) {
        score[1] = val[0] + val[1];
    }
    if (N > 2) {
        score[2] = max(val[0]+val[2], val[1]+val[2]);
    }

    for (int i = 3; i < N; ++i) {
        score[i] = max(score[i-3] + val[i-1] + val[i],score[i-2] + val[i]);
    }

    cout << score[N-1];
}