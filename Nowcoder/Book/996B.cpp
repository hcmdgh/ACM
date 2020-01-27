#include <iostream>
using namespace std;

typedef long long ll;
int T, M, H;

ll quick_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % M;
        }
        b >>= 1;
        a = (a * a) % M;
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &M, &H);
        ll sum = 0;
        while (H--) {
            ll a, b;
            scanf("%lld%lld", &a, &b);
            ll res = quick_pow(a, b);
            sum = (sum + res) % M;
        }
        printf("%lld\n", sum);
    }

    return 0;
}