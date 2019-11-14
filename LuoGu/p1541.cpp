#include <iostream>
#include <climits>
using namespace std;

#define MAX(a, b, c, d) (max(a, max(b, max(c, d))))

int N, M;
int scores[355];
int cards_cnt[5];
int dp[55][55][55][55];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", scores + i);
    }
    for (int i = 1; i <= M; ++i) {
        int card;
        scanf("%d", &card);
        ++cards_cnt[card];
    }
    dp[0][0][0][0] = scores[1];
    for (int a = 0; a <= cards_cnt[1]; ++a) {
        for (int b = 0; b <= cards_cnt[2]; ++b) {
            for (int c = 0; c <= cards_cnt[3]; ++c) {
                for (int d = 0; d <= cards_cnt[4]; ++d) {
                    int _dp = INT_MIN;
                    int score = scores[1+a+b*2+c*3+d*4];
                    if (a > 0)
                        _dp = max(_dp, dp[a-1][b][c][d]);
                    if (b > 0)
                        _dp = max(_dp, dp[a][b-1][c][d]);
                    if (c > 0)
                        _dp = max(_dp, dp[a][b][c-1][d]);
                    if (d > 0)
                        _dp = max(_dp, dp[a][b][c][d-1]);
                    if (_dp > INT_MIN)
                        dp[a][b][c][d] = _dp + score;
                }
            }
        }
    }

    printf("%d\n", dp[cards_cnt[1]][cards_cnt[2]][cards_cnt[3]][cards_cnt[4]]);

    return 0;
}
