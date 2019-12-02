#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
int N, M, K;
int arr[805][805];
int dp[805][805][20][2];

// dp[i][j][k][m]:在(i,j)位置，当两人相差量为k(小a-uim)，
// 如果m=0表示轮到小a走，如果m=1表示轮到uim走，此时的方案数。

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int k = 0; k <= K; ++k) {
        dp[1][1][k][0] = arr[1][1] == k;
        dp[1][1][k][1] = 0;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i > 1 || j > 1) {
                for (int k = 0; k <= K; ++k) {
                    dp[i][j][k][0] = (
                                             dp[i - 1][j][(k - arr[i][j] + K + 1) % (K + 1)][1] +
                                             dp[i][j - 1][(k - arr[i][j] + K + 1) % (K + 1)][1]
                                     ) % MOD;
                    dp[i][j][k][1] = (
                                             dp[i - 1][j][(k + arr[i][j] + K + 1) % (K + 1)][0] +
                                             dp[i][j - 1][(k + arr[i][j] + K + 1) % (K + 1)][0]
                                     ) % MOD;
                }
                ++dp[i][j][arr[i][j]][0];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            ans = (ans + dp[i][j][0][1]) % MOD;
        }
    }
    printf("%lld\n", ans);

    return 0;
}