#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
int N, M;
ll arr[35][35];
ll dp[35][35];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%lld", &arr[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        dp[0][M-1] = 0;
        for (int len = M - 1; len >= 0; --len) {
            for (int j = 0; j < M - len + 1; ++j) {
                int _i = j, _j = j + len - 1;
                dp[_i][_j] = max(dp[_i-1][_j] + arr[i][_i-1]*(1<<(M-_j+_i-1)),
                                 dp[_i][_j+1] + arr[i][_j+1]*(1<<(M-_j+_i-1)));
            }
        }
        ll _ans = 0;
        for (int j = 0; j < M; ++j) {
            _ans = max(_ans, dp[j][j] + arr[i][j] * (1 << M));
        }
        ans += _ans;
    }
    printf("%lld\n", ans);

    return 0;
}
