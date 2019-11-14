#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int Q, H, N;
set<int, greater<int>> heights;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &H, &N);
        heights.clear();
        for (int i = 0; i < N; ++i) {
            int height;
            scanf("%d", &height);
            heights.emplace(height);
        }
        if (N == 1) {
            printf("0\n");
            continue;
        }
        int pos = H;
        int ans = 0;
        while (pos > 0) {
            if (heights.count(pos - 1)) {
                pos -= 2;
                if (!heights.count(pos) && pos > 0) {
                    ++ans;
                }
            } else {
                auto iter = heights.upper_bound(pos);
                if (iter == heights.end())
                    break;
                pos = *iter + 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
