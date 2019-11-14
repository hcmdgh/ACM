#include <iostream>
using namespace std;

int N, M;
const int MOD = 1e9 + 7;
typedef long long ll;
ll dp[100005];

int main() {
    scanf("%d%d", &N, &M);
    dp[1] = 2, dp[2] = 4;
    int maxmn = max(N, M);
    for (int i = 3; i <= maxmn; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    ll ans = (dp[M] - 2 + dp[N]) % MOD;
    printf("%lld\n", ans);

    return 0;
}
