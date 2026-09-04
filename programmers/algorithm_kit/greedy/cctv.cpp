// Level 3, 단속카메라
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> cctv;
    sort(routes.begin(),routes.end(), cmp);
    for (vector<int> v : routes) {
        bool encounter = false;
        int start = v[0]; int end = v[1];
        for (int i : cctv) {
            if (start <= i && end >= i) {
                encounter = true; continue;
            }
        }
        if (!encounter) {
            cctv.push_back(end); ++answer;
        }
    }
    return answer;
}