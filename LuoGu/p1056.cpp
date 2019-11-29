#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K, L, D;
typedef pair<int, int> Pair;
Pair x_cnt[1005], y_cnt[1005];

bool cmp(const Pair& p1, const Pair& p2) {
    return p1.second < p2.second;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d%d", &N, &M, &K, &L, &D);
    for (int i = 1; i <= N; ++i) {
        x_cnt[i].second = i;
    }
    for (int i = 1; i <= M; ++i) {
        y_cnt[i].second = i;
    }
    while (D--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) {
            int miny = min(y1, y2);
            ++y_cnt[miny].first;
        } else {
            int minx = min(x1, x2);
            ++x_cnt[minx].first;
        }
    }
    sort(x_cnt + 1, x_cnt + 1 + N, greater<Pair>());
    sort(y_cnt + 1, y_cnt + 1 + M, greater<Pair>());
    sort(x_cnt + 1, x_cnt + 1 + K, cmp);
    sort(y_cnt + 1, y_cnt + 1 + L, cmp);
    for (int i = 1; i <= K; ++i) {
        printf("%d ", x_cnt[i].second);
    }
    putchar('\n');
    for (int i = 1; i <= L; ++i) {
        printf("%d ", y_cnt[i].second);
    }
    putchar('\n');

    return 0;
}