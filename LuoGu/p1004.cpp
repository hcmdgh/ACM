#include <iostream>

using namespace std;

#define MAX2(a, b) (((a) > (b)) ? (a) : (b))
#define MAX(a, b, c, d) MAX2(a, MAX2(b, MAX2(c, d)))

int layout[10][10];
int dp[10][10][10][10];

int main() {
    int N;
    cin >> N;
    int X, Y, V;
    while ((cin >> X >> Y >> V) && X != 0) {
        layout[X][Y] = V;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int m = 1; m <= N; ++m) {
                for (int n = 1; n <= N; ++n) {
                    dp[i][j][m][n] = MAX(
                            dp[i - 1][j][m - 1][n],
                            dp[i - 1][j][m][n - 1],
                            dp[i][j - 1][m - 1][n],
                            dp[i][j - 1][m][n - 1]
                    ) + layout[i][j] + layout[m][n];
                    if (i == m && j == n)
                        dp[i][j][m][n] -= layout[i][j];
                }
            }
        }
    }

    cout << dp[N][N][N][N] << endl;

    return 0;
}