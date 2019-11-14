#include <iostream>
using namespace std;

typedef unsigned long long ll;
int T, N;
ll A, B;
int F[1005][3005];
int period[1005];

int quick_pow(ll a, ll n, int p) {
    a %= p;
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % p;
        }
        n >>= 1;
        a = a * a % p;
    }
    return int(res);
}

void init() {
    for (int n = 2; n <= 1000; ++n) {
        F[n][0] = 0, F[n][1] = 1;
        int i = 2;
        while (true) {
            F[n][i] = (F[n][i-1] + F[n][i-2]) % n;
            if (F[n][i-1] == 0 && F[n][i] == 1) {
                period[n] = i - 1;
                break;
            }
            ++i;
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%llu%llu%d", &A, &B, &N);
        if (N == 1 || A == 0) {
            printf("0\n");
        } else {
            int ab = quick_pow(A, B, period[N]);
            printf("%d\n", F[N][ab]);
        }
    }

    return 0;
}
