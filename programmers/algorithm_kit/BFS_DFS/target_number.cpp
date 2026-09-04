// Level 2, 타겟 넘버
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    queue<int> q; q.push(numbers[0]); q.push(-numbers[0]);
    queue<int> q1;
    for (int i = 1; i < numbers.size(); ++i) {
        while (!q.empty()) {
            int f = q.front(); q.pop();
            q1.push(f+numbers[i]);
            q1.push(f-numbers[i]);
        }
        q = q1; q1 = {};
    }
    
    vector<int> v(1001, 0);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        if (f > 0 && f < 1001) {
            v[f]++;
        }
    }
    return v[target];
}