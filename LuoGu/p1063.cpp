#include <iostream>
using namespace std;

int N;
int arr[205];
int dp[205][205];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
        arr[i + N] = arr[i];
    }
    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i + len - 1 <= N * 2; ++i) {
            int end = i + len;
            dp[i][end] = -1;
            for (int j = i + 1; j <= end - 1; ++j) {
                dp[i][end] = max(dp[i][end], dp[i][j] + dp[j][end] + arr[i] * arr[end] * arr[j]);
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, dp[i][i+N]);
    }
    printf("%d\n", ans);

    return 0;
}
