#include <iostream>
using namespace std;

typedef long long ll;
ll N, P;
ll D, W;

void exgcd(ll a, ll b, ll& d, ll& x, ll& y) {
    if (b == 0) {
        d = a, x = 1, y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%lld%lld%lld%lld", &N, &P, &W, &D) == 4) {
        ll x, y, d;
        exgcd(W, D, d, x, y);
//        printf("x=%lld,y=%lld,d=%lld\n", x, y, d);
        if (P % d) {
            printf("-1\n");
        } else {
            ll x0 = x * (P / d);
            ll y0 = y * (P / d);
            ll a1 = W / d;
            ll b1 = D / d;
            bool solved = false;
            for (int k = -1000000; k < 1000000; ++k) {
                ll _x = x0 + k * b1;
                ll _y = y0 - k * a1;
                ll _z = N - _x - _y;
                if (_x >= 0 && _y >= 0 && _z >= 0) {
                    printf("%lld %lld %lld\n", _x, _y, _z);
                    solved = true;
                    break;
                }
            }
            if (!solved) {
                printf("-1\n");
            }
        }
    }

    return 0;
}
