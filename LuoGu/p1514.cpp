#include <iostream>
using namespace std;

int N, M;
int arr[505][505];
typedef pair<int, int> Pair;
Pair ranges[505][505];
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    Pair& range = ranges[x][y];
    if (range.first > -1)
        ;
    else {
        int height = arr[x][y];
        if (x == N) {
            range.first = range.second = y;
        } else {
            range.first = M + 1;
            range.second = 0;
        }
        for (int d = 0; d < 4; ++d) {
            int next_x = x + DIRECTIONS_X[d];
            int next_y = y + DIRECTIONS_Y[d];
            if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M) {
                if (arr[next_x][next_y] < height) {
                    dfs(next_x, next_y);
                    const Pair& _range = ranges[next_x][next_y];
                    range.first = min(range.first, _range.first);
                    range.second = max(range.second, _range.second);
                }
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                scanf("%d", &arr[i][j]);
                ranges[i][j].first = -1;
                ranges[i][j].second = -1;
            }
        }
        for (int i = 1; i <= M; ++i) {
            dfs(1, i);
        }
        int unable_cnt = 0;
        for (int i = 1; i <= M; ++i) {
            if (ranges[N][i].first == -1) {
                ++unable_cnt;
            }
        }
        if (unable_cnt) {
            printf("0\n%d\n", unable_cnt);
        } else {
            int R = 0, pos = 1, cnt = 0;
            while (R < M) {
                int bound = R + 1;
                for (int i = pos; i <= M; ++i) {
                    if (ranges[1][i].first <= ranges[1][i].second) {
                        if (ranges[1][i].first <= bound) {
                            R = max(R, ranges[1][i].second);
                        } else {
                            pos = i;
                            break;
                        }
                    }
                }
                if (R < bound)
                    break;
                ++cnt;
            }
            printf("1\n%d\n", cnt);
        }
    }

    return 0;
}