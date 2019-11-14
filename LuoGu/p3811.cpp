#include <iostream>
using namespace std;

typedef long long ll;
int N, P;

ll quick_pow(ll a, int n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % P;
        }
        n >>= 1;
        a = a * a % P;
    }
    return res;
}

// 求num在模P下的逆元
ll inv(ll num) {
    return quick_pow(num, P - 2);
}

int main() {
    scanf("%d%d", &N, &P);
    for (int i = 1; i <= N; ++i) {
        printf("%lld\n", inv(i));
    }

    return 0;
}
