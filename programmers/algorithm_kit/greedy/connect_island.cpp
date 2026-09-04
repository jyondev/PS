// Level 3, 섬 연결하기
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int getRoot(vector<int>& roots, int cur) {
    if (roots[cur] == cur) return cur;
    return getRoot(roots,roots[cur]);
}

void connect(vector<int>& roots, int n1, int n2) {
    int root1 = getRoot(roots, n1);
    int root2 = getRoot(roots, n2);
    if (root1 < root2) {
        roots[root2] = root1;
    }
    else {
        roots[root1] = root2;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> roots(n);
    for (int i = 0; i < n; ++i) {
        roots[i] = i;
    }
    sort(costs.begin(),costs.end(),cmp);
    for (vector<int> v : costs) {
        if (getRoot(roots, v[0]) != getRoot(roots, v[1])) {
            connect(roots,v[0],v[1]);
            answer += v[2];
        }
    }
    return answer;
}