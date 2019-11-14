#include <iostream>
using namespace std;

int A, B, C;
typedef long long ll;
ll garbage[25][25][25];
const ll INF = 1LL << 60;

void expand(int i, int& d0, int& d1, int& d2) {
    d0 = i & 1;
    i >>= 1;
    d1 = i & 1;
    i >>= 1;
    d2 = i & 1;
}

int sign(int d0, int d1, int d2) {
    return ((d0 + d1 + d2) & 1) ? 1 : -1;
}

ll sum(int x1, int y1, int z1, int x2, int y2, int z2) {
    int dx = x2 - x1 + 1, dy = y2 - y1 + 1, dz = z2 - z1 + 1;
    ll res = 0;
    for (int i = 0; i < 8; ++i) {
        int d0, d1, d2;
        expand(i, d0, d1, d2);
        res -= garbage[x2-d0*dx][y2-d1*dy][z2-d2*dz] * sign(d0, d1, d2);
    }
    return res;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &A, &B, &C);
        for (int i = 1; i <= A; ++i) {
            for (int j = 1; j <= B; ++j) {
                for (int k = 1; k <= C; ++k) {
                    scanf("%lld", &garbage[i][j][k]);
                }
            }
        }

        // 构造前缀和数组
        for (int i = 1; i <= A; ++i) {
            for (int j = 1; j <= B; ++j) {
                for (int k = 1; k <= C; ++k) {
                    for (int m = 1; m <= 7; ++m) {
                        int d0, d1, d2;
                        expand(m, d0, d1, d2);
                        garbage[i][j][k] += garbage[i-d0][j-d1][k-d2] * sign(d0, d1, d2);
                    }
                }
            }
        }

        ll ans = -INF;
        for (int i1 = 1; i1 <= A; ++i1) {
            for (int i2 = i1; i2 <= A; ++i2) {
                for (int j1 = 1; j1 <= B; ++j1) {
                    for (int j2 = j1; j2 <= B; ++j2) {
                        ll m = 0;
                        for (int k = 1; k <= C; ++k) {
                            ll s = sum(i1, j1, 1, i2, j2, k);
                            ans = max(ans, s - m);
                            m = min(m, s);
                        }
                    }
                }
            }
        }

        printf("%lld\n", ans);
        if (T)
            putchar('\n');
    }

    return 0;
}
