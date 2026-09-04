// Tree + Recursion, [Silver 1], Time Limit: 2sec
#include <iostream>
#include <vector>
using namespace std;

void preorder(vector<int>& left, vector<int>& right, int cur) {
    if (cur == -1) return;
    cout << char(cur+'A');
    preorder(left,right,left[cur]);
    preorder(left,right,right[cur]);
}
void inorder(vector<int>& left, vector<int>& right, int cur) {
    if (cur == -1) return;
    inorder(left,right,left[cur]);
    cout << char(cur+'A');
    inorder(left,right,right[cur]);
}
void postorder(vector<int>& left, vector<int>& right, int cur) {
    if (cur == -1) return;
    postorder(left,right,left[cur]);
    postorder(left,right,right[cur]);
    cout << char(cur+'A');
}

int main() {
    int N; cin >> N;
    vector<int> left(N, -1);
    vector<int> right(N, -1);

    for (int i = 0; i < N; ++i) {
        char A,B,C; cin >> A >> B >> C;
        if (B != '.') {
            left[A-'A'] = B-'A';
        }
        if (C != '.') {
            right[A-'A'] = C-'A';
        }
    }

    preorder(left, right, 0); cout << '\n';
    inorder(left,right,0); cout << '\n';
    postorder(left,right,0); cout << '\n';
}