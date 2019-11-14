#include <iostream>
using namespace std;

typedef long long ll;
int A, B, K, N, M;
const int MOD = 10007;
ll c[1005][1005];

ll quick_pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll C(int n, int k) {
    ll& _c = c[n][k];
    if (_c)
        return _c;
    if (n == k || k == 0)
        return _c = 1;
    return _c = (C(n-1, k) + C(n-1, k-1)) % MOD;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d%d%d%d", &A, &B, &K, &N, &M);
    ll res = C(K, N) * quick_pow(A, N) * quick_pow(B, M) % MOD;
    printf("%lld\n", res);

    return 0;
}
