// Floyd, [Gold 4], Time Limit: 1sec
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> price(n+1,vector<int>(n+1,100000000));
    for (int i = 0; i < m; ++i) {
        int a,b,c; cin >> a >> b >> c;
        if (c < price[a][b]) {
            price[a][b] = c;
        }
    }
    for (int i = 1; i <= n; ++i) {
        price[i][i]=0;
    }
    for (int k = 1; k < n+1; ++k) { // k: 경유지
        for (int i = 1; i < n+1; ++i) { // i: 출발지
            for (int j = 1; j < n+1; ++j) { // j: 도착지
                price[i][j] = (price[i][j] > price[i][k] + price[k][j]) ?
                    price[i][k] + price[k][j] : price[i][j];
            }
        }
    }

    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (price[i][j] == 100000000) price[i][j] = 0;
            cout << price[i][j] << " ";
        }
        cout << '\n';
    }
}