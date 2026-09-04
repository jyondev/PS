// Deque, [Gold 5], Time Limit: 1
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

deque<int> extract(string st) {
    deque<int> d;
    string s = st;
    s.erase(0,1); s.pop_back();
    
    stringstream ss(s);
    string num;

    while (getline(ss, num, ',')) {
        d.push_back(stoi(num));
    }

    return d;
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        string p; cin >> p;
        int n; cin >> n;
    
        bool reverse = false;
        bool error = false;
        string input; cin >> input;
        deque<int> d = extract(input);
        
        for (int a = 0; a < p.length(); ++a) {
            if (p[a] == 'R') {
                reverse = reverse ? false : true;
            }
            if (p[a] == 'D') {
                if (d.empty()) {
                    error = true; 
                    break;
                }
                if (reverse) {
                    d.pop_back();
                } else {
                    d.pop_front();
                }
            }
        }


        if (error) cout << "error" << '\n';
        else {
            cout << "[";
            if (reverse) {
                for (int a = d.size() - 1; a >= 0; --a) {
                    cout << d[a];
                    if (a > 0) cout << ",";
                }
            } else {
                for (int a = 0; a < d.size(); ++a) {
                    cout << d[a];
                    if (a < d.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}