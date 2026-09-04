// Level 1, 모의고사
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    int c1 = 0; int c2 = 0; int c3 = 0;
    for (int i = 0; i < answers.size(); ++i) {
        if (p1[i%p1.size()] == answers[i]) ++c1;
        if (p2[i%p2.size()] == answers[i]) ++c2;
        if (p3[i%p3.size()] == answers[i]) ++c3;
    }
    
    vector<int> answer;
    if (c1 >= c2 && c1 >= c3) {
        answer.push_back(1);
    } 
    if (c2 >= c3 && c2 >= c1) {
        answer.push_back(2);
    }
    if (c3 >= c1 && c3 >= c2) {
        answer.push_back(3);
    }
    return answer;
}