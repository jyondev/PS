// Level 3, 입국 심사
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long max 
        = (long long)(*max_element(times.begin(), times.end())) * n;
    long long min = 1;
    long long mid;
    
    while (max >= min) {
        mid = (max+min)/2;
        
        long long count = 0;
        for (int i : times) {
            count += (mid/i);
        }
        
        if (count >= n) {
            answer = mid;
            max = mid-1;
        } else {
            min = mid+1;
        }
    }
    return answer;
}