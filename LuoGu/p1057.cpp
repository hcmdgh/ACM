#include <iostream>
using namespace std;

int N, M;
int dp[31][30];  // dp[i][j]表示i次传送到编号j的方法数

int main() {
    cin >> N >> M;

    dp[0][0] = 1;
    for (int i = 1; i < N; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = dp[i-1][(j-1+N)%N] + dp[i-1][(j+1)%N];
        }
    }
    cout << dp[M][0] << endl;

    return 0;
}