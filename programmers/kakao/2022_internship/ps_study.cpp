// Level 3, 코딩테스트 공부
// DP+BFS, algorithm의 min,max 활용으로 인덱스 관리가 중요
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int m_algo = 0; int m_code = 0;
    for (vector<int> v : problems) {
        if (m_algo < v[0]) m_algo = v[0];
        if (m_code < v[1]) m_code = v[1];
    }
    if (alp >= m_algo && cop >= m_code) return 0;
    m_algo = max(m_algo,alp);
    m_code = max(m_code,cop);
    
    vector<vector<int>> ability(m_algo+1,vector<int>(m_code+1,500)); // [알고력][코딩력]=시간
    ability[alp][cop] = 0;
    queue<pair<int,int>> q; // {알고력,코딩력}
    q.push({alp,cop});
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        if (p.first < m_algo && 
            ability[p.first+1][p.second] > ability[p.first][p.second] + 1) {
            ability[p.first+1][p.second] = ability[p.first][p.second]+1;
            q.push({p.first+1,p.second});
        }
        if (p.second < m_code && 
            ability[p.first][p.second+1] > ability[p.first][p.second] + 1) {
            ability[p.first][p.second+1] = ability[p.first][p.second]+1;
            q.push({p.first,p.second+1});
        }
        for (vector<int>& v : problems) {
            if (p.first >= v[0] && p.second >= v[1]) {
                int algo = min(m_algo, p.first+v[2]);
                int code = min(m_code, p.second+v[3]);
                if (ability[algo][code] > ability[p.first][p.second]+v[4]) {
                    ability[algo][code] = ability[p.first][p.second]+v[4];
                    if (!(algo == m_algo && code == m_code)) {
                        q.push({algo,code});
                    }
                }
            }
        }
    }
    return ability[m_algo][m_code];
}