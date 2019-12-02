#include <iostream>
using namespace std;

typedef __int128 ll;
int N, M;
ll arr[85][85];
ll dp[85][85];
int digits[100];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &M);
    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &arr[i][j]);
        }

        for (int j = 1; j <= M; ++j) {
            dp[j][1] = arr[i][j] << M;
        }
        for (int len = 2; len <= M; ++len) {
            for (int j = 1; j <= M - len + 1; ++j) {
                int round = M - len + 1;
                dp[j][len] = max(
                        (arr[i][j] << round) + dp[j + 1][len - 1],
                        (arr[i][j + len - 1] << round) + dp[j][len - 1]
                );
            }
        }
        ans += dp[1][M];
    }
    int cnt = 0;
    while (ans > 0) {
        digits[cnt++] = ans % 10;
        ans /= 10;
    }
    if (cnt) {
        while (--cnt >= 0) {
            putchar('0' + digits[cnt]);
        }
        putchar('\n');
    } else {
        printf("0\n");
    }

    return 0;
}