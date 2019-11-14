#include <iostream>
using namespace std;

int N, M, T;
int money[105], _time[105];
int dp[105][205][205];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d%d", &N, &M, &T);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", money + i, _time + i);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            for (int k = 0; k <= T; ++k) {
                if (j >= money[i] && k >= _time[i]) {
                    dp[i][j][k] = max(dp[i-1][j-money[i]][k-_time[i]] + 1, dp[i-1][j][k]);
                } else {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    printf("%d\n", dp[N][M][T]);

    return 0;
}
