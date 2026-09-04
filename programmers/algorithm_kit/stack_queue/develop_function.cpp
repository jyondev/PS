// Level 2, 기능개발
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for (int i = 0; i < progresses.size(); ++i) {
        if ((100 - progresses[i]) % speeds[i] == 0) {
            progresses[i] = (100-progresses[i])/speeds[i];
        } else {
            progresses[i] = (100-progresses[i])/speeds[i]+1;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < progresses.size(); ++i) {
        q.push(progresses[i]);
    }
    while (!q.empty()) {
        int count = 0;
        int f = q.front(); q.pop(); count++;
        while (!q.empty()) {
            if (q.front() > f) break;
            q.pop(); count++;
        }
        answer.push_back(count);
    }
    return answer;
}