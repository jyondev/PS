// Greedy, [Gold 5], Time Limit: 2sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<pair<int,int>> meeting; // {end, start}
    for (int i = 0; i < N; ++i) {
        int start, end; cin >> start >> end;
        meeting.push_back({end,start});
    }
    sort(meeting.begin(),meeting.end());

    int count = 0;
    int last_meeting = 0;

    for (int i = 0; i < N; ++i) {
        int start = meeting[i].second;
        int end = meeting[i].first;
        if (start >= last_meeting) {
            last_meeting = end;
            ++count;
        }
    }
    cout << count;
}