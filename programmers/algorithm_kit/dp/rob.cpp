// Level 4, 도둑질
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp1 = money; // 첫 집 털기 => 두번째 집 안털기
    dp1[1] = 0; dp1[2] = dp1[0] + dp1[2];
    vector<int> dp2 = money; // 첫 집 안털기
    dp2[0] = 0;
    for (int i = 3; i < dp1.size()-1; ++i) {
        dp1[i] = max(dp1[i-2], dp1[i-3]) + money[i];
    }
    for (int i = 3; i < dp2.size(); ++i) {
        dp2[i] = max(dp2[i-2], dp2[i-3]) + money[i];
    }
    
    return max(max(dp1[dp1.size()-2],dp1[dp1.size()-3]),
              max(dp2[dp2.size()-1], dp2[dp2.size()-2]));
}