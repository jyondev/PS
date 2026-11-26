// DP, [Gold 3], Time Limit: 0.1sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s1,s2; cin >> s1 >> s2;
    int N = s1.length(); int M = s2.length();
    vector<vector<int>> dp(N+1,vector<int>(M+1,0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[N][M] << '\n';

    vector<char> vv;
    while (N != 0 && M != 0) {
        if (s1[N-1] == s2[M-1]) {
            vv.push_back(s1[N-1]);
            N -= 1; M -= 1;
        } else {
            if (dp[N][M] == dp[N-1][M]) {
                N -= 1;
            } else {
                M -= 1;
            }
        }
    }

    for (int i = vv.size() - 1; i >= 0; --i) {
        cout << vv[i];
    }
}