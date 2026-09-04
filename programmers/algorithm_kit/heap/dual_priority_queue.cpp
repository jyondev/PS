// Level 3, 이중 우선순위 큐
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms; // 중복 허용, 자동 정렬, 앞과 끝 접근 가능
    for (string s : operations) {
        char cmd = s[0];
        int data = stoi(s.substr(s.find(' ')+1));
        if (cmd == 'I') {
            ms.insert(data);
            continue;
        }
        if (!ms.empty()) {
            if (data == 1) {
                ms.erase(prev(ms.end()));
            }
            else {
                ms.erase(ms.begin());
            }
        }
    }
    if (ms.empty()) return {0,0};
    else return {*prev(ms.end()),*ms.begin()};
}