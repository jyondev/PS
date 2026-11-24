// DP, [Silver 4], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> sugar(N+1,INT_MAX);
    sugar[0] = 0;

    for (int i = 1; i <= N; ++i) {
        if (i >= 3 && sugar[i-3] != INT_MAX) {
            sugar[i] = min(sugar[i], sugar[i-3] + 1);
        }
        if (i >= 5 && sugar[i-5] != INT_MAX) {
            sugar[i] = min(sugar[i], sugar[i-5] + 1);
        }
    }

    if (sugar[N] == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }
    cout << sugar[N] << '\n';
}
