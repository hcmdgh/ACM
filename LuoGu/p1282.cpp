#include <iostream>
using namespace std;

int N;
int a[1005], b[1005];
int dp[1005][6005];
const int INF = 0x3F3F3F3F;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", a + i, b + i);
        sum += a[i] + b[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 6 * N; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[1][b[1]] = 1;
    dp[1][a[1]] = 0;
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= 6 * i; ++j) {
            if (j - a[i] > 0)
                dp[i][j] = min(dp[i][j], dp[i-1][j-a[i]]);
            if (j - b[i] > 0)
                dp[i][j] = min(dp[i][j], dp[i-1][j-b[i]] + 1);
        }
    }
    int ans = -1, min_delta = INF;
    for (int i = 1; i <= 6 * N; ++i) {
        int delta = abs(i - (sum - i));
        if (delta < min_delta) {
            min_delta = delta;
            ans = dp[N][i];
        } else if (delta == min_delta) {
            ans = min(ans, dp[N][i]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
