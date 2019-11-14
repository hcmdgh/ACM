#include <iostream>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

const char RGB[4] = "RGB";
int dp[200000][3];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        int N, K;
        string str;
        cin >> N >> K >> str;

        memset(dp, 0, sizeof(int) * N * 3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < K; ++j) {
                if (str[j] != RGB[(i + j) % 3])
                    ++dp[0][i];
            }
        }

        int ans = min(min(dp[0][0], dp[0][1]), dp[0][2]);
        for (int i = 1; i < N - K + 1; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = dp[i-1][(j+2)%3] + (str[i+K-1] != RGB[(K+j+2)%3]) - (str[i-1] != RGB[(j+2)%3]);
                ans = min(ans, dp[i][j]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}