#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
int N;
struct Rect {
    ll width, height;

    void set(ll len1, ll len2) {
        width = max(len1, len2);
        height = min(len1, len2);
    }

    bool operator<(const Rect& other) const {
        return width > other.width;
    }
} rects[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) {
            ll len1, len2;
            scanf("%lld%lld", &len1, &len2);
            rects[i].set(len1, len2);
        }
        sort(rects, rects + N);
        ll max_area = 0;
        ll max_height = 0;
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            max_area = max(max_area, rects[i].width * rects[i].height);
            ans = max(ans, max_area);
            ans = max(ans, 2 * rects[i].width * min(max_height, rects[i].height));
            max_height = max(max_height, rects[i].height);
        }
        if (ans & 1) {
            printf("%lld.5\n", ans >> 1);
        } else {
            printf("%lld.0\n", ans >> 1);
        }
    }

    return 0;
}