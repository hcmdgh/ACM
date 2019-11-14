#include <cstdio>
#include <set>
#include <cassert>
using namespace std;

typedef pair<int, int> Pair;
set<Pair> ans;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int k;
    while (scanf("%d", &k) == 1) {
        ans.clear();
        int k2 = k * k;
        for (int i = 1; i * i <= k2; ++i) {
            if (k2 % i == 0) {
                int x = i + k;
                int y = (k * x) / (x - k);
                assert(y > 0);
                if (x >= y) {
                    ans.emplace(Pair(y, x));
                }

                x = k2 / i + k;
                y = ((long long)k * x) / (x - k);
//                if (y < 0) {
//                    printf("i=%d k=%d x=%d y=%d\n", i, k, x, y);
//                }
                if (x >= y) {
                    ans.emplace(Pair(y, x));
                }
            }
        }
        printf("%d\n", ans.size());
        for (auto p : ans) {
            printf("1/%d = 1/%d + 1/%d\n", k, p.second, p.first);
        }
    }

    return 0;
}
