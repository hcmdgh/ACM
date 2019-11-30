#include <iostream>
#include <climits>
using namespace std;

int N, M, R, C;
int arr[20][20];
int rows[20];
int diff_row[20];
int diff_col[20][20];
int dp[20][20];
int ans;

void func_dp() {
    for (int j = 1; j <= M; ++j) {
        diff_row[j] = 0;
        for (int i = 1; i <= R - 1; ++i) {
            diff_row[j] += abs(arr[rows[i]][j] - arr[rows[i + 1]][j]);
        }
    }
    for (int i = 1; i <= M - 1; ++i) {
        for (int j = i + 1; j <= M; ++j) {
            diff_col[i][j] = 0;
            for (int k = 1; k <= R; ++k) {
                diff_col[i][j] += abs(arr[rows[k]][i] - arr[rows[k]][j]);
            }
        }
    }

    for (int i = 1; i <= M; ++i) {
        int max_j = min(i, C);
        for (int j = 1; j <= max_j; ++j) {
            if (j == 1) {
                dp[i][j] = diff_row[i];
            } else {
                dp[i][j] = INT_MAX;
                for (int k = j - 1; k <= i - 1; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + diff_row[i] + diff_col[k][i]);
                }
            }
        }
    }
    for (int i = C; i <= M; ++i) {
        ans = min(ans, dp[i][C]);
    }
}

void dfs(int pos) {
    if (pos > R) {
        func_dp();
    } else {
        for (int i = rows[pos - 1] + 1; i <= N - (R - pos); ++i) {
            rows[pos] = i;
            dfs(pos + 1);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d%d", &N, &M, &R, &C) == 4) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                scanf("%d", &arr[i][j]);
            }
        }
        rows[0] = 0;
        ans = INT_MAX;
        dfs(1);
        printf("%d\n", ans);
    }

    return 0;
}