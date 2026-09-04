// Level 2, 구명보트
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end(),greater<int>());
    stack<int> st;
    for (int i : people) {
        if (!st.empty() && st.top() + i <= limit) {
            ++answer; st.pop(); continue;
        }
        st.push(i);
    }
    answer += st.size();
    return answer;
}