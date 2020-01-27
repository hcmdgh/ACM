#include <iostream>
using namespace std;

typedef long long ll;
ll t1, t2;

ll calc(ll t) {
    return t / 60 * 50 + min(t % 60, 50LL);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%lld%lld", &t1, &t2) == 2) {
        ll res = calc(t2) - calc(t1 - 1);
        printf("%lld\n", res);
    }

    return 0;
}