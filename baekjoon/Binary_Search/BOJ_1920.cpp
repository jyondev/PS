// Binary Search, [Silver 4], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 함수 선언 (STL 금지 시)
bool binary_search(vector<int>& v, int val) {
    int start = 0;
    int end = v.size() - 1;
    while (start <= end) {
        int mid = (start + end)/2;
        if (v[mid] == val) return true;
        else if (v[mid] > val) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}

int main() {
    int N; cin >> N;
    vector<int> cor(N);
    for (int i = 0; i < N; ++i) {
        cin >> cor[i];
    }

    int M; cin >> M;
    vector<int> num(M);
    for (int i = 0; i < M; ++i) {
        cin >> num[i];
    }

    sort(cor.begin(), cor.end());
    for (int i : num) {
        cout << (binary_search(cor.begin(), cor.end(), i) ? 1 : 0) << '\n';
    }
}