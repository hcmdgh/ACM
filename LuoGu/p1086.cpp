#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;
struct Grid {
    int x, y, peanut;

    bool operator<(const Grid& other) const {
        return peanut > other.peanut;
    }
} grids[405];
int grids_cnt;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d", &M, &N, &K) == 3) {
        grids_cnt = 0;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                int num;
                scanf("%d", &num);
                if (num > 0) {
                    grids[grids_cnt].x = i;
                    grids[grids_cnt].y = j;
                    grids[grids_cnt].peanut = num;
                    ++grids_cnt;
                }
            }
        }
        sort(grids, grids + grids_cnt);
        int last_x = -1, last_y = -1;
        int total = 0;
        for (int i = 0; i < grids_cnt; ++i) {
            int x = grids[i].x, y = grids[i].y, peanut = grids[i].peanut;
            int cost;
            if (last_x == -1) {
                cost = x;
            } else {
                cost = abs(x - last_x) + abs(y - last_y);
            }
            K -= cost + 1;
            if (K < x)
                break;
            total += peanut;
            last_x = x, last_y = y;
        }
        printf("%d\n", total);
    }

    return 0;
}