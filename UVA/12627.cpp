#include <iostream>
#include <cmath>
using namespace std;

int T, K, A, B;
typedef long long ll;

ll dfs(int t, int r) {
    if (r == 0)
        return 0;
    if (t == 0) {
        return 1;
    } else {
        if (r <= (1 << (t-1))) {
            return 2 * dfs(t - 1, r);
        } else {
            return 2 * pow(3, t - 1) + dfs(t - 1, r - (1 << (t-1)));
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d%d%d", &K, &A, &B);
        ll ans = dfs(K, B) - dfs(K, A - 1);
        printf("Case %d: %lld\n", kase, ans);
    }

    return 0;
}
