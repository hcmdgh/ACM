#include <iostream>
using namespace std;

#define MAX(a, b, c, d) (max(a, max(b, max(c, d))))

int N, M;
int graph[55][55];
int dp[55][55][55][55];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i1 = 1; i1 <= N; ++i1) {
        for (int j1 = 1; j1 <= M; ++j1) {
            for (int i2 = 1; i2 <= N; ++i2) {
                for (int j2 = 1; j2 <= M; ++j2) {
                    if (i1 == i2 && j1 == j2) {
                        dp[i1][j1][i2][j2] = 0;
                    } else {
                        dp[i1][j1][i2][j2] = MAX(
                            dp[i1-1][j1][i2-1][j2],
                            dp[i1-1][j1][i2][j2-1],
                            dp[i1][j1-1][i2-1][j2],
                            dp[i1][j1-1][i2][j2-1]
                        ) + graph[i1][j1] + graph[i2][j2];
                    }
                }
            }
        }
    }
    printf("%d\n", dp[N][M-1][N-1][M]);

    return 0;
}
