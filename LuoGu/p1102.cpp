#include <iostream>
using namespace std;

long long dp[21][21];
const int DIRECTIONS_X[8] = {1, 1, -1, -1, 2, -2, 2, -2};
const int DIRECTIONS_Y[8] = {2, -2, 2, -2, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    int N, M, MX, MY;
    cin >> N >> M >> MX >> MY;
    ++N, ++M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 1;
    dp[MX][MY] = 0;
    for (int i = 0; i < 8; ++i) {
        int x = MX + DIRECTIONS_X[i];
        int y = MY + DIRECTIONS_Y[i];
        if (x >= 0 && x < N && y >= 0 && y < M) {
            dp[x][y] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            long long& _dp = dp[i][j];
            if (_dp == -1) {
                _dp = 0;
                if (i > 0)
                    _dp += dp[i - 1][j];
                if (j > 0)
                    _dp += dp[i][j - 1];
            }
        }
    }

    cout << dp[N - 1][M - 1] << endl;

    return 0;
}