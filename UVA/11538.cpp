#include <iostream>
using namespace std;

typedef long long ll;
int M, N;

ll C(int n, int m) {
    m = min(m, n - m);
    ll ans = 1;
    for (int i = 1; i <= m; ++i) {
        ans = ans * (n - i + 1) / i;
    }
    return ans;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d", &M, &N) == 2 && N && M) {
        int bound = min(N, M);
        ll ans = 0;
        for (int i = 2; i < bound; ++i) {
            ans += C(i, 2) * 4;
        }
        ans += C(bound, 2) * 2 * (abs(N - M) + 1);
        ans *= 2;
        ans += C(M, 2) * 2 * N + C(N, 2) * 2 * M;
        printf("%lld\n", ans);
    }

    return 0;
}
