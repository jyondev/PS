// Level 2, 올바른 괄호
#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st; st.push(s[0]);
    for (int i = 1; i < s.length(); ++i) {
        if (st.empty()) {
            if (s[i] == ')') return false;
            else {
                st.push(s[i]); continue;
            }
        }
        if (s[i] == ')' && st.top() == '(') {
            st.pop(); continue;
        }
        st.push(s[i]);
    }
    if (!st.empty()) return false;
    return true;
}