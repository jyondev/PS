// Level 2, 소수 찾기
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

set<int> makeNumbers(string n) {
    set<int> s;
    sort(n.begin(),n.end());
    do {
        for (int i = 1; i <= n.size(); ++i) {
            string sub = n.substr(0,i);
            if (sub[0] == '0') continue;
            if (sub == "1") continue;
            s.insert(stoi(sub));
        }
    } while (next_permutation(n.begin(),n.end()));
    
    return s;
}

int solution(string numbers) {
    set<int> s = makeNumbers(numbers);
    int answer = 0;
    for (int i : s) {
        bool b = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                b = false; break;
            }
        }
        if (b) ++answer;
    }
    return answer;
}