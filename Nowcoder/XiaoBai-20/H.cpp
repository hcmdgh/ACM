#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
typedef pair<int, int> Pair;
Pair points[500005], ans[500005];
int ans_cnt = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &points[i].first, &points[i].second);
    }
    sort(points, points + N, greater<Pair>());
    int last_y = INT_MIN;
    for (int i = 0; i < N; ++i) {
        if (points[i].second > last_y) {
            ans[ans_cnt++] = points[i];
            last_y = points[i].second;
        }
    }
    sort(ans, ans + ans_cnt);
    for (int i = 0; i < ans_cnt; ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}