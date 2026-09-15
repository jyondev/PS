// Level 3, 등굣길

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(n+1, vector<int>(m+1,0));
    for (vector<int>& v : puddles) {
        map[v[1]][v[0]] = -1;
    }
    map[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == -1) continue;
            else {
                if (i < n && map[i+1][j] != -1) {
                    map[i+1][j] += map[i][j];
                    map[i+1][j] %= 1000000007;
                }
                if (j < m && map[i][j+1] != -1) {
                    map[i][j+1] += map[i][j];
                    map[i][j+1] %= 1000000007;
                }
            }
        }
    }
    return map[n][m];
}


// #include <string>
// #include <vector>

// using namespace std;

// int solution(int m, int n, vector<vector<int>> puddles) {
//     vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
//     dp[1][1] = 1;
//     for (vector<int> v : puddles) {
//         dp[v[1]][v[0]] = -1;
//     }
    
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             if (i == 1 && j == 1) continue;
//             if (dp[i][j] == -1) continue;
//             int left=0,up=0;
//             if (dp[i-1][j] != -1) {
//                 up = dp[i-1][j];
//             }
//             if (dp[i][j-1] != -1) {
//                 left = dp[i][j-1];
//             }
//             dp[i][j] = (up+left) % 1000000007;
//         }
//     }
//     return dp[n][m];
// }