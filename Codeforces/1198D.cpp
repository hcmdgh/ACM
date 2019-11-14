#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int N;
bool layout[50][50];
const bool BLACK = false;
const bool WHITE = true;
int dp[50][50][50][50];

int dfs(int x1, int y1, int x2, int y2) {
    int& _dp = dp[x1][y1][x2][y2];
    if (_dp != -1)
        return _dp;
    _dp = max(x2 - x1, y2 - y1) + 1;
    for (int i = x1; i < x2; ++i) {
        _dp = min(_dp, dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
    }
    for (int j = y1; j < y2; ++j) {
        _dp = min(_dp, dfs(x1, y1, x2, j) + dfs(x1, j + 1, x2, y2));
    }
    return _dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char ch;
            cin >> ch;
            layout[i][j] = (ch == '#') ? BLACK : WHITE;
        }
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j][i][j] = (layout[i][j] == BLACK) ? 1 : 0;
        }
    }
    cout << dfs(0, 0, N - 1, N - 1) << endl;

    return 0;
}