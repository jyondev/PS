#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int,int>> height; // {idx, height}
    vector<int> receiver;

    int f; cin >> f;
    height.push_back({1, f});
    receiver.push_back(0);

    for (int i = 1; i < N; ++i) {
        int h; cin >> h;
        while (!height.empty()) {
            if (h >= height[height.size() - 1].second) {
                height.pop_back();
            } else break;
        }

        if (height.empty()) {
            height.push_back({i+1,h});
            receiver.push_back(0);
            continue;
        }

        if (h < height[height.size() - 1].second) {
            receiver.push_back(height[height.size() - 1].first);
            height.push_back({i+1,h});
        }
    }

    for (int i : receiver) {
        cout << i << " ";
    }
}