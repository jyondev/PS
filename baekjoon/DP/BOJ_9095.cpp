// DP, [Silver 3], Time Limit: 1sec
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; cin >> T;
    vector<int> dp(12,0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 11; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        cout << dp[N] << '\n';
    }
}