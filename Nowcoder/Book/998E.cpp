#include <iostream>
#include <climits>
using namespace std;

// dp[i] = min{dp[j] * 2 + f[i-1-j] * 2 + 1}
// f[i] = f[i - 1] * 2 + 1
int f[15], dp[15];

int main() {
    f[1] = 1;
    for (int i = 2; i <= 12; ++i) {
        f[i] = f[i - 1] * 2 + 1;
    }
    dp[1] = 1;
    for (int i = 2; i <= 12; ++i) {
        dp[i] = INT_MAX;
        for (int j = 0; j <= i - 1; ++j) {
            dp[i] = min(dp[i], dp[j] * 2 + f[i - 1 - j] * 2 + 1);
        }
    }
    for (int i = 1; i <= 12; ++i) {
        printf("%d\n", dp[i]);
    }

    return 0;
}