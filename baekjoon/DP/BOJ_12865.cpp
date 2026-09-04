// DP, [Gold 5], Time Limit: 2sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 풀이 1
void backtrack(vector<pair<int,int>>& items, vector<vector<int>>& value
    , int curWeight, int curValue, int curIdx) {
    if (curIdx == items.size()) return;
    int w = curWeight + items[curIdx].first;
    int v = curValue + items[curIdx].second;
    if (w < value[0].size() && v > value[curIdx][w]) {
        value[curIdx][w] = v;
        backtrack(items,value,w,v,curIdx+1);
    }
    backtrack(items,value,curWeight,curValue,curIdx+1);
}

int main() {
    int N,K; cin >> N >> K;

    vector<pair<int,int>> items(N); // {무게,가치}
    vector<vector<int>> value(N,vector<int>(K+1,0)); // [확인한 인덱스][무게]

    for (int i = 0; i < N; ++i) {
        int W,V; cin >> W >> V;
        items[i] = {W,V};
    }

    backtrack(items,value,0,0,0);

    int m = 0;
    for (vector<int> v : value) {
        vector<int>::iterator it = max_element(v.begin(),v.end());
        if (m < *it) m = *it;
    }
    cout << m;
}

// 풀이2
int main() {
    int N,K; cin >> N >> K;
    vector<int> value(K+1,0);
    for (int i = 0; i < N; ++i) {
        int W,V; cin >> W >> V;
        for (int j = K; j >= W; --j) {
            value[j] = max(value[j], value[j-W]+V);
        }
    }

    vector<int>::iterator it = max_element(value.begin(),value.end());
    cout << *it;
}