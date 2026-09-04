// Level 1, 실패율
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<double,int>& a, const pair<double,int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> failure_rate(N);
    for (int i = 0; i < N; ++i) {
        failure_rate[i] = {0,i+1}; // 실패율,번호
    }
    for (int i : stages) {
        failure_rate[i-1].first++; // 사람 수
    }
    int count = 0; int size = stages.size();
    for (int i = 0; i < failure_rate.size(); ++i) {
        if (count == size) break;
        int c = failure_rate[i].first;
        failure_rate[i].first = (failure_rate[i].first / (size-count));
        count += c;
    }
    sort(failure_rate.begin(),failure_rate.end(),cmp);
    for (int i = 0; i < failure_rate.size(); ++i) {
        answer.push_back(failure_rate[i].second);
    }
    return answer;
}