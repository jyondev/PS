// Level 3, 스티커 모으기
// DP
/*
1. 상태 정의 (배열이 의미하는게 무엇인지)
2. 초기값 세팅 (배열의 초기 원소 채워넣기)
3. 점화식 도출
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) {
        return sticker[0];
    }
    vector<int> dp1(sticker.size(),0); // 0번 스티커 때는 경우
    vector<int> dp2(sticker.size(),0); // 0번 스티커 안 때는 경우
    dp1[0] = sticker[0]; dp1[1] = dp1[0];
    dp2[0] = 0; dp2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); ++i) {
        dp1[i] = max(dp1[i-2]+sticker[i], dp1[i-1]);
        dp2[i] = max(dp2[i-2]+sticker[i], dp2[i-1]);
    }
    return max(dp1[sticker.size()-2],dp2[sticker.size()-1]);
}