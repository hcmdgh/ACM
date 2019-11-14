#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int T, N;
struct Food {
    int a, b, c;

    bool operator<(const Food& other) const {
        return (ll)b * other.c > (ll)c * other.b;
    }
} foods[55];
ll dp[100005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &T, &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &foods[i].a);
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &foods[i].b);
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &foods[i].c);
    }
    sort(foods + 1, foods + N + 1);
    ll ans = -1;
    for (int i = 1; i <= N; ++i) {
        for (int j = T; j >= foods[i].c; --j) {
            dp[j] = max(dp[j], dp[j - foods[i].c] + foods[i].a - (ll)j * foods[i].b);
            ans = max(ans, dp[j]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
