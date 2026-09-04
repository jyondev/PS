// Level 2, H-Index
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end(),greater<int>());
    int answer = 0;
    for (int i = 0; i < citations.size(); ++i) {
        int idx = i+1;
        if (citations[i] >= idx) {
            ++answer;
        } else break;
    }
    return answer;
}