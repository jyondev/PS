// Queue, [Silver 4], Time Limit: 2sec
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    queue<int> deck;
    for (int i = 1; i <= N; ++i) {
        deck.push(i);
    }

    while (deck.size() != 1) {
        deck.pop();
        int f = deck.front();
        deck.push(f);
        deck.pop();
    }

    cout << deck.front();
}