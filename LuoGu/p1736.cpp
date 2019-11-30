#include <iostream>
#include <cstring>
using namespace std;

int N, M;
bool layout[2505][2505];
int dp[2505][2505];
int left_space[2505][2505];
int up_space[2505][2505];
int right_space[2505][2505];

#define MIN(a, b, c) (min(a, min(b, c)))

bool readChar() {
    char ch;
    do {
        ch = getchar();
    } while (ch != '0' && ch != '1');
    return ch == '1';
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        memset(layout, 0, sizeof(layout));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                layout[i][j] = readChar();
            }
        }
        for (int j = 1; j <= M; ++j)
            up_space[1][j] = 0;
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (!layout[i-1][j]) {
                    up_space[i][j] = up_space[i-1][j] + 1;
                } else {
                    up_space[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= N; ++i)
            left_space[i][1] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 2; j <= M; ++j) {
                if (!layout[i][j-1]) {
                    left_space[i][j] = left_space[i][j-1] + 1;
                } else {
                    left_space[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= N; ++i)
            right_space[i][M] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = M - 1; j >= 1; --j) {
                if (!layout[i][j+1]) {
                    right_space[i][j] = right_space[i][j+1] + 1;
                } else {
                    right_space[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= M; ++j) {
            dp[1][j] = layout[1][j];
            ans = max(ans, dp[1][j]);
        }
        for (int i = 2; i <= N; ++i) {
            dp[i][1] = layout[i][1];
            ans = max(ans, dp[i][1]);
        }
        for (int i = 2; i <= N; ++i) {
            for (int j = 2; j <= M; ++j) {
                if (layout[i][j]) {
                    dp[i][j] = MIN(dp[i - 1][j - 1], left_space[i][j], up_space[i][j]) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        for (int j = 1; j <= M; ++j) {
            dp[1][j] = layout[1][j];
            ans = max(ans, dp[1][j]);
        }
        for (int i = 2; i <= N; ++i) {
            dp[i][M] = layout[i][M];
            ans = max(ans, dp[i][M]);
        }
        for (int i = 2; i <= N; ++i) {
            for (int j = M - 1; j >= 0; --j) {
                if (layout[i][j]) {
                    dp[i][j] = MIN(dp[i - 1][j + 1], right_space[i][j], up_space[i][j]) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}