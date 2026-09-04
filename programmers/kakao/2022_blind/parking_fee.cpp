// Level 2, 주차 요금 계산
// 구현
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;
    for (string s : records) {
        stringstream ss(s);
        string clock,number,inout;
        ss >> clock >> number >> inout;
        m[number].push_back(clock);
    }
    for (pair<string,vector<string>> p : m) {
        int fee = fees[1];
        int time_count = 0;
        if (p.second.size() % 2 == 1) {
            p.second.push_back("23:59");
        }
        for (int i = 0; i < p.second.size(); ++i) {
            int s1 = stoi(p.second[i].substr(0,2));
            int s2 = stoi(p.second[i].substr(3,2));
            if (i % 2 == 0) {
                time_count -= (60*s1);
                time_count -= s2;
            } else {
                time_count += (60*s1);
                time_count += s2;
            }
        }
        time_count -= fees[0];
        if (time_count <= 0) {
            answer.push_back(fee);
        } else {
            int f = time_count / fees[2];
            if (time_count % fees[2] != 0) {
                ++f;
            }
            fee += (f * fees[3]);
            answer.push_back(fee);
        }
    }
    return answer;
}