#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> refine(string s) {
    vector<char> v;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')') {
            v.push_back(s[i]);
        }
    }
    return v;
}

bool check(vector<char> f, vector<char> b) {
    if (f.empty() && b.empty()) return true;
    vector<char> front = f;
    vector<char> back = b;

    while (!front.empty()) {
        if (front.back() == ')' || front.back() == ']') {
            back.push_back(front.back());
            front.pop_back();
        } else break;
    }
    if (front.empty()) return false;
    if (back.empty()) return false;

    while (!back.empty()) {
        if (front.empty()) return false;
        if (front.back() == '(' && back.back() == ')') {
            front.pop_back();
            back.pop_back();
        }
        else if (front.back() == '[' && back.back() == ']') {
            front.pop_back();
            back.pop_back();
        } else {
            break;
        }
    }

    if (front.empty() && back.empty()) return true;
    if (!front.empty() && (front.back() == ')' || front.back() == ']')) {
        return check(front, back);
    }
    return false;
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s == ".") break;
        vector<char> v = refine(s);
        vector<char> vacant;
        if (check(v, vacant)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}