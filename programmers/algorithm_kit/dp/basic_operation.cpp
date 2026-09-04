// Level 4, 사칙연산
// min_dp, max_dp로 dp 2개 운용
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<string> arr)
{
    vector<int> num;
    vector<char> oper;
    for (int i = 0; i < arr.size(); ++i) {
        if (i % 2 == 0) {
            num.push_back(stoi(arr[i]));
        } else {
            oper.push_back(arr[i][0]);
        }
    }
    int n = num.size();
    vector<vector<int>> max_dp(n,vector<int>(n,-100000));
    vector<vector<int>> min_dp(n,vector<int>(n,300000));
    for (int i = 0; i < num.size(); ++i) {
        max_dp[i][i] = num[i];
        min_dp[i][i] = num[i];
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n-l; ++i) {
            int j = i+l-1;
            for (int k = i; k < j; ++k) {
                if (oper[k] == '+') {
                    max_dp[i][j] = max(max_dp[i][j],max_dp[i][k]+max_dp[k+1][j]);
                    min_dp[i][j] = min(min_dp[i][j],min_dp[i][k]+min_dp[k+1][j]);
                } else {
                    max_dp[i][j] = max(max_dp[i][j],max_dp[i][k]-min_dp[k+1][j]);
                    min_dp[i][j] = min(min_dp[i][j],min_dp[i][k]-max_dp[k+1][j]);
                }
            }
        }
    }
    return max_dp[0][n-1];
}