#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool layout[205][205];
int group[205][205];
int _group[205][205];
char _map[8] = "xWAKJSD";

void dfs_black(int x, int y, int idx) {
    if (x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1 && layout[x][y] && group[x][y] == 0) {
        group[x][y] = idx;
        dfs_black(x + 1, y, idx);
        dfs_black(x - 1, y, idx);
        dfs_black(x, y + 1, idx);
        dfs_black(x, y - 1, idx);
    }
}

void dfs_white(int x, int y, int idx) {
    if (x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1 && _group[x][y] == 0) {
        _group[x][y] = idx;
        dfs_white(x + 1, y, idx);
        dfs_white(x - 1, y, idx);
        dfs_white(x, y + 1, idx);
        dfs_white(x, y - 1, idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int Q = 0;
    while ((cin >> N >> M) && N > 0 && M > 0) {
        ++Q;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                char ch;
                cin >> ch;
                int digit = ch >= 'a' ? ch - 'a' + 10 : ch - '0';
                layout[i][j * 4 - 3] = digit / 8;
                layout[i][j * 4 - 2] = digit / 4 % 2;
                layout[i][j * 4 - 1] = digit / 2 % 2;
                layout[i][j * 4] = digit % 2;
            }
        }
        M <<= 2;
        for (int i = 0; i <= N + 1; ++i) {
            layout[i][0] = layout[i][M+1] = false;
        }
        for (int i = 0; i <= M + 1; ++i) {
            layout[0][i] = layout[N+1][i] = false;
        }
        for (int i = 0; i <= N + 1; ++i) {
            for (int j = 0; j <= M + 1; ++j) {
                group[i][j] = 0;
            }
        }

        int block_cnt = 0;
        vector<char> ans;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (layout[i][j] && group[i][j] == 0) {
                    ++block_cnt;
                    dfs_black(i, j, block_cnt);
                    for (int ii = 0; ii <= N + 1; ++ii) {
                        for (int jj = 0; jj <= M + 1; ++jj) {
                            if (group[ii][jj] == block_cnt) {
                                _group[ii][jj] = -1;
                            } else {
                                _group[ii][jj] = 0;
                            }
                        }
                    }
                    int hole_cnt = 0;
                    for (int ii = 0; ii <= N + 1; ++ii) {
                        for (int jj = 0; jj <= M + 1; ++jj) {
                            if (_group[ii][jj] == 0) {
                                ++hole_cnt;
                                dfs_white(ii, jj, hole_cnt);
                            }
                        }
                    }
                    ans.emplace_back(_map[hole_cnt]);
                }
            }
        }

        sort(ans.begin(), ans.end());
        cout << "Case " << Q << ": ";
        for (char ch : ans) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
