// Level 1, '폰켓몬'

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size();
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if (nums.size() < N/2) {
        return nums.size();
    }
    return N/2;
}