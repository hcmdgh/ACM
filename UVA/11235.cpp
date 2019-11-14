#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int N, Q;
int st[100005][20];
struct Segment {
    int value;
    int _left, _right;
} segments[100005];
int seg[100005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    while (scanf("%d%d", &N, &Q) == 2 && N > 0) {
        segments[0].value = INT_MAX;
        int seg_cnt = 0;
        for (int i = 1; i <= N; ++i) {
            int val;
            scanf("%d", &val);
            if (val != segments[seg_cnt].value) {
                ++seg_cnt;
                segments[seg_cnt].value = val;
                segments[seg_cnt]._left = i;
                segments[seg_cnt]._right = i;
            } else {
                segments[seg_cnt]._right = i;
            }
            seg[i] = seg_cnt;
        }

        for (int i = 1; i <= seg_cnt; ++i)
            st[i][0] = segments[i]._right - segments[i]._left + 1;
        for (int j = 1; (1<<j) <= seg_cnt; ++j) {
            for (int i = 1; i + (1<<j) - 1 <= seg_cnt; ++i) {
                st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }

        while (Q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            int l_idx = seg[l];
            int r_idx = seg[r];
            if (l_idx == r_idx) {
                printf("%d\n", r - l + 1);
            } else {
                Segment l_seg = segments[l_idx];
                Segment r_seg = segments[r_idx];
                int ans = max(l_seg._right - l + 1, r - r_seg._left + 1);
                int begin = seg[l] + 1;
                int end = seg[r] - 1;
                if (begin <= end) {
                    int len = end - begin + 1;
                    int k = 0;
                    while ((1<<(k+1)) <= len)
                        ++k;
                    ans = max(ans, max(st[begin][k], st[end - (1<<k) + 1][k]));
                }
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}
