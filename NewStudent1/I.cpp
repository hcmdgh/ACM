#include <iostream>
using namespace std;

typedef long long ll;
ll X, Y, N;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%lld%lld%lld", &X, &Y, &N);
    ll _gcd = gcd(X, Y);
    X /= _gcd;
    Y /= _gcd;
    ll lcm = X * Y;
    ll res = N / X + N / Y - N / lcm;
    res = N - N / _gcd;
    printf("%lld\n", res);

    return 0;
}