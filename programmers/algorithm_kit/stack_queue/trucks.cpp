// Level 2, 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_weight = 0;
    int cur_idx = 0;
    queue<int> bridge;
    for (int i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }
    while (cur_idx < truck_weights.size()) {
        ++answer;
        cur_weight -= bridge.front(); bridge.pop();
        int next = 0;
        if (cur_weight + truck_weights[cur_idx] <= weight) {
            next = truck_weights[cur_idx];
            ++cur_idx;
        }
        cur_weight += next; bridge.push(next);
    }
    answer += bridge_length;
    return answer;
}