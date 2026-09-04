// DFS, [Silver 1], Time Limit: 1sec
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& building, pair<int, int> cur, int& h) {
    building[cur.first][cur.second] = 0; ++h;
    int move_row[4] = {0,1,0,-1};
    int move_column[4] = {1,0,-1,0};

    for (int a = 0; a < 4; ++a) {
        int row = cur.first + move_row[a];
        int column = cur.second + move_column[a];
        if (row >= 0 && row < building.size() && column >= 0 && column <
            building[0].size()) {
                if (building[row][column]) {
                    DFS(building, {row, column}, h);
                }
        }
    }
}

int main() {
    int N; cin >> N;
    vector<vector<int>> building(N, vector<int>(N,0));
    for (int i = 0; i < N; ++i) {
        string n; cin >> n;
        for (int j = 0; j < N; ++j) {
            building[i][j] = n[j] - '0';
        }
    }

    int complex = 0;
    vector<int> house;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (building[i][j]) {
                ++complex;
                int h = 0;
                DFS(building, {i,j}, h);
                house.push_back(h);
            }
        }
    }

    sort(house.begin(), house.end());

    cout << complex << '\n';
    for (int h : house) {
        cout << h << '\n';
    }
}