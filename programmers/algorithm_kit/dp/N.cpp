// Level 3, N으로 표현
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<set<int>> dp(9);
    int base = N;
    for (int i = 1; i < 9; ++i) {
        dp[i].insert(base);
        base = base * 10 + N;
    }
    
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int p : dp[j]) {
                for (int q : dp[i-j]) {
                    dp[i].insert(p+q);
                    dp[i].insert(p-q);
                    dp[i].insert(p*q);
                    if (q!=0) dp[i].insert(p/q);
                }
            }
        }
        if (dp[i].count(number)) return i;
    }
    return -1;
}