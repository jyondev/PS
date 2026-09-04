// Level 2, 후보키
// 비트마스크를 활용하여 배열을 쓰지 않고 구현
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int row_size = relation.size();
    int col_size = relation[0].size();
    vector<int> answer;
    for (int i = 1; i < (1 << col_size); ++i) { 
        // 2^(col_size)-1만큼 반복문
        // column 선택 시 비트가 1 (0001)
        set<string> s;
        for (int r = 0; r < row_size; ++r) {
            string tmp = "";
            for (int c = 0; c < col_size; ++c) {
                if (i & (1<<c)) {
                    tmp += relation[r][c] + ",";
                }
            }
            s.insert(tmp);
        }
        
        if (s.size() == row_size) {
            bool isUnique = true;
            
            for (int key : answer) {
                if ((i & key) == key) {
                    isUnique = false; break;
                }
            }
            
            if (isUnique) answer.push_back(i);
        }
    }
    return answer.size();
}