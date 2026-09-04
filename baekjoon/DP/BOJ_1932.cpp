// DP, [Silver 1], Time Limit: 2sec]
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> triangle(n,vector<int>(n));
    vector<vector<int>> score(n,vector<int>(n,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i+1; ++j) {
            cin >> triangle[i][j];
        }
    }

    score[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
        score[i][0] = score[i-1][0]+triangle[i][0];
        score[i][i] = score[i-1][i-1]+triangle[i][i];
        for (int j = 1; j < i; ++j) {
            score[i][j] = triangle[i][j] + max(score[i-1][j], score[i-1][j-1]);
        }
    }

    vector<int>::iterator it = max_element(score[n-1].begin(),score[n-1].end());
    cout << *it;
}