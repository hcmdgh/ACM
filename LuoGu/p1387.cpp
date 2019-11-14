#include <iostream>
using namespace std;

int N, M;
bool graph[105][105];
int dp[105][105];
int _up[105][105], _left[105][105];

bool readBool() {
    while (true) {
        char ch = getchar();
        if (ch == '0')
            return false;
        if (ch == '1')
            return true;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            graph[i][j] = readBool();
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (graph[i-1][j]) {
                _up[i][j] = _up[i-1][j] + 1;
            } else {
                _up[i][j] = 0;
            }
            if (graph[i][j-1]) {
                _left[i][j] = _left[i][j-1] + 1;
            } else {
                _left[i][j] = 0;
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (!graph[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(_left[i][j], _up[i][j])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
