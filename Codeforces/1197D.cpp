// 动态转移方程：
// dp[i][j]表示以第i个数结尾，序列长度%m=j的最大cost
// dp[i][j] = dp[i-1][j-1] + a[i] (j > 1)
// dp[i][j] = max(dp[i-1][0] - k + a[i], a[i]) (j == 1)
// dp[i][j] = dp[i-1][m-1] + a[i] (j == 0)

#include <iostream>
#include <climits>
using namespace std;

int N, M, K;
long long arr[300001];
long long dp[300001][10];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < M; ++i) {
        dp[0][i] = INT_MIN;
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j == 1 || M == 1) {
                dp[i][j] = max(dp[i - 1][0] - K + arr[i], arr[i] - K);
            } else if (j == 0) {
                dp[i][j] = dp[i-1][M-1] + arr[i];
            } else {
                dp[i][j] = dp[i-1][j-1] + arr[i];
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}