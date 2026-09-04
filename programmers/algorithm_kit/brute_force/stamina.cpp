// Level 2, 피로도
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    set<vector<int>> s;
    sort(dungeons.begin(), dungeons.end());
    do {
        int count = 0;
        int stamina = k;
        for (vector<int> v : dungeons) {
            if (stamina >= v[0]) {
                stamina -= v[1]; ++count;
            } else break;
        }
        if (answer < count) answer = count;
    } while (next_permutation(dungeons.begin(),dungeons.end()));
    
    return answer;
}