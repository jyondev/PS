// DP, [Silver 1], Time Limit: 0.5sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> cost[N];
    vector<int> rgb[N];
    for (int i = 0; i < N; ++i) {
        cost[i].resize(3);
        rgb[i].resize(3);
    }
    for (int i = 0; i < N; ++i) {
        int r,g,b; cin >> r >> g >> b;
        rgb[i][0] = r; rgb[i][1] = g; rgb[i][2] = b;
    }
    cost[0][0] = rgb[0][0];
    cost[0][1] = rgb[0][1];
    cost[0][2] = rgb[0][2];

    for (int i = 1; i < N; ++i) {
        cost[i][0] = rgb[i][0] + min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] = rgb[i][1] + min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] = rgb[i][2] + min(cost[i-1][0], cost[i-1][1]);
    }

    cout << min({cost[N-1][0], cost[N-1][1], cost[N-1][2]});
}