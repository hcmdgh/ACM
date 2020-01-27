#include <iostream>
using namespace std;

typedef long long ll;
ll A, B, P;

ll quick_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % P;
        }
        b >>= 1;
        a = (a * a) % P;
    }
    return res % P;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%lld%lld%lld", &A, &B, &P);
    ll res = quick_pow(A, B);
    printf("%lld\n", res);

    return 0;
}