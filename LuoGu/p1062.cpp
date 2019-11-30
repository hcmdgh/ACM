#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
int K, N;
int digits[1005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &K, &N);
    int len = 0;
    while (N > 0) {
        digits[len++] = N & 1;
        N >>= 1;
    }
    ll res = 0;
    for (int i = 0; i < len; ++i) {
        if (digits[i]) {
            res += pow(K, i);
        }
    }
    printf("%lld\n", res);

    return 0;
}