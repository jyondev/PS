// DP, [Silver 3], Time Limit: 0.25sec
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        vector<pair<int,int>> dp(N+1, {0,0});
        dp[0] = {1,0};
        dp[1] = {0,1};
        for (int i = 2; i <= N; ++i) {
            dp[i] = {dp[i-2].first + dp[i-1].first,
                dp[i-2].second + dp[i-1].second};
        }

        cout << dp[N].first << " " << dp[N].second << '\n';
    }
}