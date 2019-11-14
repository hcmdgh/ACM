#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int N;
bool src[20][20];
bool dest[20][20];
const int DIRECTIONS_X[3] = {0, 0, -1};
const int DIRECTIONS_Y[3] = {1, -1, 0};

bool even(int x, int y) {
    int sum = 0;
    for (int d = 0; d < 3; ++d) {
        int next_x = x + DIRECTIONS_X[d];
        int next_y = y + DIRECTIONS_Y[d];
        if (next_x >= 0 && next_y >= 0 && next_y < N) {
            sum += dest[next_x][next_y];
        }
    }
    return sum & 1;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &src[i][j]);
            }
        }

        memset(dest, 0, sizeof(dest));
        int min_tran = INT_MAX;
        while (!dest[0][N]) {
            for (int i = 1; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dest[i][j] = even(i-1, j);
                }
            }
            int tran = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    bool& _src = src[i][j];
                    bool& _dest = dest[i][j];
                    if (_src != _dest) {
                        if (_src) {
                            tran = INT_MAX;
                            goto end;
                        } else {
                            ++tran;
                        }
                    }
                }
            }
            end:
            min_tran = min(tran, min_tran);

            int carry = 1, j = 0;
            while (carry) {
                int temp = dest[0][j] + carry;
                carry = temp >> 1;
                dest[0][j] = temp & 1;
                ++j;
            }
        }
        if (min_tran == INT_MAX)
            min_tran = -1;
        printf("Case %d: %d\n", t + 1, min_tran);
    }

    return 0;
}
