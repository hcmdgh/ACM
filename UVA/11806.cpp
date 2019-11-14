#include <iostream>
using namespace std;

int M, N, K;
const int MOD = 1000007;
const int MAXK = 500;
int C[MAXK + 5][MAXK + 5];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    for (int i = 0; i <= MAXK; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d%d%d", &M, &N, &K);
        int ans = 0;
        for (int state = 0; state < 16; ++state) {
            int row = M, column = N, cnt = 0;
            if (state & 1)
                ++cnt, --row;
            if (state & 2)
                ++cnt, --row;
            if (state & 4)
                ++cnt, --column;
            if (state & 8)
                ++cnt, --column;
            int c = C[row * column][K];
            if (cnt & 1) {
                ans = (ans - c + MOD) % MOD;
            } else {
                ans = (ans + c) % MOD;
            }
        }
        printf("Case %d: %d\n", t + 1, ans);
    }

    return 0;
}
