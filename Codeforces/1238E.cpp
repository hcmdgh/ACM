#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char S[100005];
int cnt[30][30];
int dp[(1 << 21) + 5];

int countBit(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt += (num & 1);
        num >>= 1;
    }
    return cnt;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d", &N, &M) == 2) {
        scanf("%s", S);
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0x3F, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < N - 1; ++i) {
            int idx1 = S[i] - 'a';
            int idx2 = S[i+1] - 'a';
            if (idx1 != idx2) {
                ++cnt[idx1][idx2], ++cnt[idx2][idx1];
            }
        }
        for (int i = 0; i < (1 << M); ++i) {
            int len = countBit(i);
            for (int j = 0; j < M; ++j) {
                if (!(i & (1 << j))) {
                    int cost = dp[i];
                    for (int k = 0; k < M; ++k) {
                        if (i & (1 << k)) {
                            cost += cnt[j][k] * len;
                        } else {
                            cost -= cnt[j][k] * len;
                        }
                    }
                    dp[i|(1<<j)] = min(dp[i|(1<<j)], cost);
                }
            }
        }
        printf("%d\n", dp[(1<<M)-1]);
    }

    return 0;
}
