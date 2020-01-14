#include <iostream>
using namespace std;

int N, C;
int dis[55], power[55];
int sum[55];
int dp[55][55][2];
const int INF = 0x3F3F3F3F;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &C);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", dis + i, power + i);
        sum[i] = sum[i - 1] + power[i];
    }
    for (int i = 1; i <= N; ++i) {
        dp[i][i][0] = dp[i][i][1] = INF;
    }
    dp[C][C][0] = dp[C][C][1] = 0;
    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i <= N - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j][0] = min(
                    dp[i+1][j][0] + (dis[i+1] - dis[i]) * (sum[i] + sum[N] - sum[j]),
                    dp[i+1][j][1] + (dis[j] - dis[i]) * (sum[i] + sum[N] - sum[j])
            );
            dp[i][j][1] = min(
                    dp[i][j-1][1] + (dis[j] - dis[j-1]) * (sum[i-1] + sum[N] - sum[j-1]),
                    dp[i][j-1][0] + (dis[j] - dis[i]) * (sum[i-1] + sum[N] - sum[j-1])
            );
        }
    }
    int ans = min(dp[1][N][0], dp[1][N][1]);
    printf("%d\n", ans);

    return 0;
}