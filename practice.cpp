#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int main() {
    string word;
    int N; cin >> N; 
    stack<int> st; 
    set<int> s; 
    queue<int> q;
    priority_queue<int> pq;
    multiset<int> ms; 
}

/*
stoi(string): 문자열을 숫자로
isdigit(char): char이 숫자인지 판별
next_permutation(begin,end): 
    사전식 순서로 순열 재배치 후 true 반환
multiset<int> ms: 
    이중 우선순위 큐 구현 시 사용
    중복 허용, 자동 정렬
    begin, end, insert, erase

set<int> s:
    중복 허용X, 자동 정렬
    원소 접근은 iterator 이용
    begin, end, erase
queue<int> q:
    FIFO
    push, pop, front
priority_queue<int> pq:
    FIFO, 자동 정렬
    struct{operator()(~~)}를 사용해 정렬 구조 만들기 가능
        priority_queue<int,vector<int>,cmp>
    push, pop, top
stack<int> st:
    LIFO
    push, pop, top
*/
