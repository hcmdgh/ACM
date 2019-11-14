#include <iostream>
using namespace std;

typedef long long ll;
ll T, N, M;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        ll odd1 = 0;
        for (int i = 0; i < N; ++i) {
            int val;
            scanf("%d", &val);
            if (val & 1)
                ++odd1;
        }
        scanf("%d", &M);
        ll odd2 = 0;
        for (int i = 0; i < M; ++i) {
            int val;
            scanf("%d", &val);
            if (val & 1)
                ++odd2;
        }
        ll ans = odd1 * odd2 + (N - odd1) * (M - odd2);
        printf("%I64d\n", ans);
    }

    return 0;
}
