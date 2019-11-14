#include <iostream>
using namespace std;

int N, V;  // N:物品总数 V:背包的最大容积
int w[1005], v[1005];  // w:每件物品的体积 v:每件物品的价值
int dp[1005];
// dp[i][j]表示用前j件物品装容积为i的背包能取得的最大价值
// 状态转移方程：dp[i][j] = max{dp[i][j-1], dp[i-w[j]][j-1]+v[j]}

int main() {
    scanf("%d%d", &N, &V);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", w + i, v + i);
    }
    for (int j = 1; j <= N; ++j) {
        for (int i = V; i >= w[j]; --i) {
            dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
        }
    }
    printf("%d\n", dp[V]);

    return 0;
}
