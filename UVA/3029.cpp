#include <iostream>
using namespace std;

bool layout[1005][1005];
int up[1005][1005];
int _left[1005][1005];
int _right[1005][1005];

bool readLayout() {
    int ch;
    do {
        ch = getchar();
    } while (ch != 'F' && ch != 'R');
    return ch == 'F';
}

struct DP {
    int x, y;
} dp[1005][1005];

int M, N;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int K;
    scanf("%d", &K);
    while (K--) {
        scanf("%d%d", &M, &N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                layout[i][j] = readLayout();
            }
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (layout[i][j]) {
                    up[i][j] = i == 0 ? 1 : up[i-1][j] + 1;
                } else {
                    up[i][j] = 0;
                }
            }
            int left_block = -1;
            for (int j = 0; j < N; ++j) {
                if (layout[i][j]) {
                    _left[i][j] = i == 0 ? left_block + 1 : max(_left[i-1][j], left_block + 1);
                } else {
                    _left[i][j] = -1;
                    left_block = j;
                }
            }
            int right_block = N;
            for (int j = N - 1; j >= 0; --j) {
                if (layout[i][j]) {
                    _right[i][j] = i == 0 ? right_block - 1 : min(_right[i-1][j], right_block - 1);
                } else {
                    _right[i][j] = N;
                    right_block = j;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = max(ans, up[i][j] * (_right[i][j] - _left[i][j] + 1));
            }
        }
        printf("%d\n", ans * 3);
    }

    return 0;
}
