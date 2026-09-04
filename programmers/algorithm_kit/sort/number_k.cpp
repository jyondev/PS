// Level 1, K번째 수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> v : commands) {
        int i = v[0] - 1;
        int j = v[1];
        int k = v[2];
        vector<int> sub(array.begin()+i,array.begin()+j);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[k-1]);
    }
    
    return answer;
}