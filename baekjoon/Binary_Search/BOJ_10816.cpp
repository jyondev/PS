// Binary Search, [Silver 4], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// target 이상의 값이 처음으로 나오는 위치
int low_bound(const vector<int>& arr, int target) {
    int start = 0; int end = arr.size();
    while (start < end) {
        int mid = (start+end)/2;
        if (arr[mid]>=target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}
// target 초과의 값이 처음으로 나오는 위치
int upp_bound(const vector<int>& arr, int target) {
    int start = 0; int end = arr.size();
    while (start < end) {
        int mid = (start+end)/2;
        if (arr[mid]>target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int N, M;
    cin >> N; vector<int> card(N);
    for (int i = 0; i < N; ++i) {
        cin >> card[i];
    }
    sort(card.begin(), card.end());

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int num; cin >> num;
        int count = upper_bound(card.begin(), card.end(), num)
                    - lower_bound(card.begin(), card.end(), num);
        cout << count << " ";
    }
}