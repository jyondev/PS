// DP, [Gold 4], Time Limit: 2sec
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s1,s2,s3; cin >> s1 >> s2 >> s3;
    int I = s1.length();
    int J = s2.length();
    int K = s3.length();
    vector<vector<vector<int>>> dp(I+1,vector<vector<int>>(J+1,vector<int>(K+1,0)));

    for (int i = 1; i <= I; ++i) {
        for (int j = 1; j <= J; ++j) {
            for (int k = 1; k <= K; ++k) {
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                }
            }
        }
    }

    cout << dp[I][J][K] << '\n';
}