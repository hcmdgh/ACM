#include <iostream>
#include <cstring>
using namespace std;

int K1, K2, K3, N;
const int MAXN = 200005;
int num2group[MAXN];
int dp[MAXN][4];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d", &K1, &K2, &K3) == 3) {
        N = K1 + K2 + K3;
        for (int i = 0; i < K1; ++i) {
            int num;
            scanf("%d", &num);
            num2group[num] = 1;
        }
        for (int i = 0; i < K2; ++i) {
            int num;
            scanf("%d", &num);
            num2group[num] = 2;
        }
        for (int i = 0; i < K3; ++i) {
            int num;
            scanf("%d", &num);
            num2group[num] = 3;
        }
        memset(dp, 0x3F, sizeof(dp));
        dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for (int num = 1; num <= N; ++num) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= i; ++j) {
                    dp[num][i] = min(dp[num][i], dp[num - 1][j] + (i != num2group[num]));
                }
            }
        }
        int res = 0x3F3F3F3F;
        for (int i = 1; i <= 3; ++i) {
            res = min(res, dp[N][i]);
        }
        printf("%d\n", res);
    }

    return 0;
}