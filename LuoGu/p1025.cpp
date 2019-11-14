#include <iostream>
using namespace std;

int dp[201][7];

int solve(int n, int k) {
    if (k <= 0 || n <= 0 || n < k)
        return 0;
    if (n == k || k == 1)
        return 1;
    int &_dp = dp[n][k];
    if (_dp > -1)
        return _dp;
    return (_dp = solve(n-1, k-1) + solve(n-k, k));
}

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << solve(N, K) << endl;

    return 0;
}