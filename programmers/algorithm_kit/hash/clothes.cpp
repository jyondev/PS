// Level 2, 의상
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (vector<string> v : clothes) {
        m[v[1]]++;
    }
    
    int answer = 1;
    for (pair<string,int> p : m) {
        answer *= (p.second+1);
    }
    return answer-1;
}