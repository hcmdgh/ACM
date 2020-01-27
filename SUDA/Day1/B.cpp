#include <iostream>
using namespace std;

typedef long long ll;
int T;
ll A, B, C, D;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
        ll sum = A + B + C + D;
        printf("%lld\n", sum);
    }

    return 0;
}