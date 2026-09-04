// Level 3, 디스크 컨트롤러
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) return a[1]>b[1];
        if (a[0] != b[0]) return a[0]>b[0];
        if (a[2] != b[2]) return a[2]>b[2];
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    for (int i = 0; i < jobs.size(); ++i) {
        jobs[i].push_back(i);
    }
    sort(jobs.begin(),jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int cur_time = 0;
    int cur_job = 0;
    int result = 0;
    
    while (cur_job < jobs.size() || !pq.empty()) {
        while (cur_job < jobs.size() && cur_time >= jobs[cur_job][0]) {
            pq.push(jobs[cur_job]);
            ++cur_job;
        }
        
        if (!pq.empty()) {
            vector<int> v = pq.top(); pq.pop();
            cur_time += v[1];
            result += (cur_time-v[0]);
        } else {
            if (cur_job < jobs.size()) {
                cur_time = jobs[cur_job][0];
            }
        }
    }
    
    return result/jobs.size();
}