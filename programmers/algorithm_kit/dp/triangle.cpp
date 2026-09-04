// Level 3, 정수 삼각형
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> v(triangle.size());
    v[0].push_back(triangle[0][0]);
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            int left = j-1; int right = j;
            int left_parent = 0; int right_parent = 0;
            if (left >= 0) {
                left_parent = v[i-1][left];
            }
            if (right < triangle[i-1].size()) {
                right_parent = v[i-1][right];
            }
            v[i].push_back(max(left_parent,right_parent)+triangle[i][j]);
        }
    }
    return *max_element(v[v.size()-1].begin(), v[v.size()-1].end());
}