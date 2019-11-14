#include <iostream>
using namespace std;

int N, M;
int prices[105];
int dp[105][10005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", prices + i);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (j == prices[i]) {
                dp[i][j] = dp[i-1][j] + 1;
            } else if (j < prices[i]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-prices[i]];
            }
        }
    }
    printf("%d\n", dp[N][M]);

    return 0;
}
