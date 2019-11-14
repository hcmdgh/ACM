#include <iostream>
#include <algorithm>
using namespace std;

int N;
typedef pair<int, int> Pair;
Pair points[105];
int xs[105];
int _left[105]; // left[i]表示竖线i左侧位于横线上点的个数
int on[105];  // on[i]表示竖线i点的个数（不包括横线上的）
int _on[105];  // _on[i]表示竖线i点的个数（包括横线上的）
// 确定竖线i和j后，点的数量即为left[j]-left[i]+on[i]+_on[j]

bool cmp(const Pair& pair1, const Pair& pair2) {
    return pair1.second < pair2.second;
}

int solve() {
    sort(xs, xs + N);
    sort(points, points + N, cmp);
    int x_cnt = unique(xs, xs + N) - xs;
    if (x_cnt <= 2)
        return N;
    int ans = 0;
    for (int i = 0; i < x_cnt - 1; ++i) {
        for (int j = i + 1; j < x_cnt; ++j) {
            int x_max = xs[j], x_min = xs[i];
            int cnt = 0;
            for (int k = 0; k < N; ++k) {
                if (k == 0 || points[k].second != points[k - 1].second) {
                    _left[cnt] = cnt == 0 ? 0 : _left[cnt - 1] + _on[cnt - 1] - on[cnt - 1];
                    on[cnt] = _on[cnt] = 0;
                    ++cnt;
                }
                if (points[k].first > x_min && points[k].first < x_max) {
                    ++on[cnt - 1];
                }
                if (points[k].first >= x_min && points[k].first <= x_max) {
                    ++_on[cnt - 1];
                }
            }
            if (cnt <= 2)
                return N;
            int temp_max = on[0] - _left[0];
            for (int k = 1; k < cnt; ++k) {
                ans = max(ans, _left[k] + _on[k] + temp_max);
                temp_max = max(temp_max, on[k] - _left[k]);
            }
        }
    }
    return ans;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int T = 1;
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &points[i].first, &points[i].second);
            xs[i] = points[i].first;
        }
        printf("Case %d: %d\n", T, solve());
        ++T;
    }

    return 0;
}
