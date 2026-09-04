// Level 2, 게임 맵 최단거리
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void BFS(vector<vector<int>>& distance, vector<vector<int>>& maps) {
    queue<pair<int,int>> q; // 좌표 큐
    q.push({0,0});
    int move_row[4] = {0,1,0,-1};
    int move_column[4] = {1,0,-1,0};
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int row = p.first+move_row[i];
            int column = p.second+move_column[i];
            if (row >= 0 && row < maps.size() && column >= 0 && column < maps[0].size()) {
                if (maps[row][column] == 0) continue;
                if (distance[p.first][p.second] + 1 < distance[row][column]) {
                    distance[row][column] = distance[p.first][p.second] + 1;
                    q.push({row,column});
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    vector<vector<int>> distance(maps.size(),vector<int>(maps[0].size(),10001)); 
    distance[0][0] = 1;
    BFS(distance,maps);
    int result = distance[maps.size()-1][maps[0].size()-1];
    if (result == 10001) return -1;
    return result;
}