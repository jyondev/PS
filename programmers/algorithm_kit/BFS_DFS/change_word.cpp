// Level 3, 단어 변환
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool changable(string& a, string& b) {
    int count = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) ++count;
    }
    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(),words.end(),target) == words.end()) {
        return 0;
    }
    vector<bool> visited(words.size(), false);
    vector<pair<string,int>> count(words.size());
    for (int i = 0; i < words.size(); ++i) {
        count[i] = {words[i],0};
    }
    queue<pair<string,int>> q; q.push({begin,0});
    while (!q.empty()) {
        pair<string,int> p = q.front(); q.pop();
        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i] && changable(p.first, words[i])) {
                count[i].second = p.second + 1;
                visited[i] = true;
                if (words[i] == target) return count[i].second;
                q.push(count[i]);
            }
        }
    }
    return 0;
}