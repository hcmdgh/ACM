#include <iostream>
#include <cstring>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int N;
int graph[21][21];
int dp[1 << 21][21];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 1; i < (1 << N); ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i >> j) & 1) {
                for (int k = 0; k < N; ++k) {
                    if (!((i >> k) & 1)) {
                        dp[i | (1 << k)][k] = MIN(dp[i | (1 << k)][k], dp[i][j] + graph[j][k]);
                    }
                }
            }
        }
    }
    printf("%d\n", dp[(1 << N) - 1][N - 1]);

    return 0;
}