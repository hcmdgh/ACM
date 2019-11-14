#include <iostream>
#include <climits>
using namespace std;

#define MAX(x, y, z) (max(max((x), (y)), (z)))

int N, M;
int energy[201][201];
int dp[201][202];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = N; i >= 1; --i) {
        for (int j = 1; j <= M; ++j) {
            cin >> energy[i][j];
        }
    }
    for (int i = 0; i < M + 2; ++i) {
        dp[0][i] = INT_MIN;
    }
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = dp[i][M+1] = INT_MIN;
    }
    dp[0][M / 2 + 1] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int temp = MAX(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]);
            if (temp == INT_MIN)
                dp[i][j] = INT_MIN;
            else
                dp[i][j] = temp + energy[i][j];
        }
    }

    int ans = INT_MIN;
    for (int i = 1; i <= M; ++i) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;

    return 0;
}