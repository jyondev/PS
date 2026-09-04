// Level 3, 아이템 줍기
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// x1,y1,x2,y2
void BFS(vector<vector<int>>& lines, vector<int>& elem) {
    int cX = elem[0]*2; int cY = elem[1]*2; int iX = elem[2]*2; int iY = elem[3]*2;
    queue<pair<int,int>> q; q.push({cX,cY});
    int move_x[4] = {1,0,-1,0}; int move_y[4] = {0,-1,0,1};
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = p.first+move_x[i];
            int y = p.second+move_y[i];
            if (lines[x][y] == 0 || lines[x][y] > lines[p.first][p.second]+1) {
                lines[x][y] = lines[p.first][p.second]+1;
                q.push({x,y});
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> lines(102,vector<int>(102,-1));
    for (vector<int> v : rectangle) {
        for (int i = v[0]*2; i <= v[2]*2; ++i) {
            for (int j = v[1]*2; j <= v[3]*2; ++j) {
                if (i == v[0]*2 || i == v[2]*2 || j == v[1]*2 || j == v[3]*2) {
                    if (lines[i][j] != -2) {
                        lines[i][j] = 0;
                    }
                } else {
                    lines[i][j] = -2;
                }
            }
        }
    }
    lines[characterX*2][characterY*2] = 1;
    vector<int> elem = {characterX,characterY,itemX,itemY};
    BFS(lines,elem);
    return lines[itemX*2][itemY*2]/2;
}