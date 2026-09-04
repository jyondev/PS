// Level 2, 카펫
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> v;
    int total = brown + yellow;
    for (int i = 1; i <= total; ++i) {
        if (total%i == 0) {
            v.push_back(i);
        }
    }
    
    for (int i : v) {
        int j = total/i;
        if (2*i+2*j-4 == brown && (i-2)*(j-2) == yellow) {
            if (i >= j) {
                return {i,j};
            } else {
                return {j,i};
            }
        }
    }
    return {};
}