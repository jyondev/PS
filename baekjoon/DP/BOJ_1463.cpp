// DP, [Silver 3], Time Limit: 0.15sec
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> arr(N+1,INT_MAX); arr[N] = 0;
    queue<int> next; next.push(N);
    while (!next.empty() && arr[1] == INT_MAX) {
        int f = next.front(); next.pop();
        if (f <= 0) continue;
        if (f % 3 == 0) {
            if (arr[f/3] > arr[f]+1) {
                arr[f/3] = arr[f]+1;
                next.push(f/3);
            }
        }
        if (f % 2 == 0) {
            if (arr[f/2] > arr[f]+1) {
                arr[f/2] = arr[f]+1;
                next.push(f/2);
            }
        }
        if (arr[f-1] > arr[f]+1) {
            arr[f-1] = arr[f]+1;
            next.push(f-1);
        }
    }
    cout << arr[1];
}