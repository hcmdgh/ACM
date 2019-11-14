#include <iostream>
using namespace std;

int N;
// dp[i][j]表示选取前i个数使得和j的方案数
long long dp[40][781];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;

    int temp = (1 + N) * N / 2;
    if (temp & 1) {
        cout << 0 << endl;
        return 0;
    }
    int sum = temp / 2;
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j - i >= 0)
                dp[i][j] += dp[i-1][j-i];
        }
    }
    cout << dp[N][sum] / 2 << endl;

    return 0;
}
