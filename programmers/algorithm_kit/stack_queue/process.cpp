// Level 2, 프로세스
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int count = 0;
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    for (int i = 0; i < priorities.size(); ++i) {
        q1.push({i,priorities[i]});
    }
    
    while (!q1.empty()) {
        bool highest = true;
        pair<int,int> p1 = q1.front(); q1.pop();
        while (!q1.empty()) {
            pair<int,int> p2 = q1.front();
            if (p2.second > p1.second) {
                highest = false;
                while (!q1.empty()) {
                    q2.push(q1.front()); q1.pop();
                }
                q2.push(p1);
            } else {
                q2.push(p2); q1.pop();
            }
        }
        if (!highest) {
            q1 = q2; q2 = {}; continue;
        }
        if (highest) {
            ++count;
            if (p1.first == location) {
                return count;
            }
            q1 = q2; q2 = {};
        }
    }
}