// Level 3, 연속 펄스 부분 수열의 합
// DP
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    if (sequence.size() == 1) {
        return max(sequence[0],-sequence[0]);
    }
    vector<int> v1; // 1 -1 1 -1 ...
    vector<int> v2; // -1 1 -1 1 ...
    for (int i = 0; i < sequence.size(); ++i) {
        v1.push_back(sequence[i]*(i%2 == 0 ? 1 : -1));
        v2.push_back(sequence[i]*(i%2 == 0 ? -1 : 1));
    }
    
    vector<long long> dp1(sequence.size()); // v1
    vector<long long> dp2(sequence.size()); // v2
    dp1[0] = (long long)v1[0]; dp2[0] = (long long)v2[0];
    for (int i = 1; i < sequence.size(); ++i) {
        dp1[i] = (dp1[i-1]+v1[i] > v1[i]) ? dp1[i-1]+v1[i] : v1[i];
        dp2[i] = (dp2[i-1]+v2[i] > v2[i]) ? dp2[i-1]+v2[i] : v2[i];
    }
    long long m1 = *max_element(dp1.begin(),dp1.end());
    long long m2 = *max_element(dp2.begin(),dp2.end());
    return (m1 > m2) ? m1 : m2;
}