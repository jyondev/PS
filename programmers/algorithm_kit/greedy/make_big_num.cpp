// Level 2, 큰 수 만들기
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int length = number.length()-k;
    for (char c : number) {
        while (k > 0 && !answer.empty() && answer.back() < c) {
            --k; answer.pop_back();
        }
        answer.push_back(c);
    }
    answer = answer.substr(0,length);
    return answer;
}