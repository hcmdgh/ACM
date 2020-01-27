#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 9901;
ll A, B;

ll quick_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

ll sum(ll q, ll n) {
    ll inv = quick_pow(q - 1, MOD - 2);
    return (quick_pow(q, n) + MOD - 1) % MOD * inv % MOD;
}

int main() {
    scanf("%lld%lld", &A, &B);
    ll i = 2;
    ll ans = 1;
    while (A > 1) {
        if (A % i == 0) {
            ll cnt = 0;
            while (A % i == 0) {
                ++cnt;
                A /= i;
            }
            cnt *= B;
            ans = ans * sum(i, cnt + 1) % MOD;
        }
        ++i;
    }
    if (A == 0)
        ans = 0;
    printf("%lld\n", ans);

    return 0;
}