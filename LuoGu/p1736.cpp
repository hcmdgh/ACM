#include <iostream>
using namespace std;

int N, M;
bool graph[2505][2505];
int dp[2505][2505];
int _dp[2505][2505];
int _left[2505][2505];
int _up[2505][2505];
int _right[2505][2505];

bool readChar() {
    while (true) {
        char ch = getchar();
        if (ch == '0')
            return 0;
        if (ch == '1')
            return 1;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            graph[i][j] = readChar();
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (graph[i-1][j]) {
                _up[i][j] = 0;
            } else {
                _up[i][j] = _up[i-1][j] + 1;
            }
            if (graph[i][j-1]) {
                _left[i][j] = 0;
            } else {
                _left[i][j] = _left[i][j-1] + 1;
            }
        }
        for (int j = M; j >= 1; --j) {
            if (graph[i][j+1]) {
                _right[i][j] = 0;
            } else {
                _right[i][j] = _right[i][j+1] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (graph[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(_left[i][j], _up[i][j])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = M; j >= 1; --j) {
            if (graph[i][j]) {
                dp[i][j] = min(dp[i-1][j+1], min(_right[i][j], _up[i][j])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
