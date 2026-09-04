// Level 2, 조이스틱
#include <string>
#include <vector>

using namespace std;
// ABCDEFGHIJKLMNOPQRSTUVWXYZ, 26개
int solution(string name) {
    int answer = 0;
    vector<int> v(name.length());
    for (int i = 0; i < name.length(); ++i) {
        int k = name[i]-'A';
        v[i] = min(k,26-k);
    }
    for (int i : v) {
        answer += i;
    }
    if (answer == 0) return 0;
    
    int move = v.size()-1;
    for (int i = 0; i < v.size(); ++i) {
        int next = i+1; int end = next; 
        // 0->i i번 0->end v.size()-end번 이동
        while (end != v.size() && v[end] == 0) {++end;}
        end = v.size()-end;
        move = min(move, 2*i+end);
        move = min(move, i+2*end);
    }
    return answer+move;
}