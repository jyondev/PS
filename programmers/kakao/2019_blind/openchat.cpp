// Level 2, 오픈채팅방
// sstream의 stringstream 활용 문제
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m; // Id, Name
    for (string s : record) {
        string command, id, name;
        stringstream ss(s);
        ss >> command >> id >> name;
        if (command == "Enter" || command == "Change") {
            m[id] = name;
        }
    }
    
    for (string s : record) {
        string command, id, name;
        stringstream ss(s);
        ss >> command >> id >> name;
        if (command == "Enter") {
            answer.push_back(m[id] + "님이 들어왔습니다.");
        } else if (command == "Leave") {
            answer.push_back(m[id] + "님이 나갔습니다.");
        }
    }
    return answer;
}