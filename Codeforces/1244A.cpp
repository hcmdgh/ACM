#include <iostream>
using namespace std;

int T, A, B, C, D, K;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &A, &B, &C, &D, &K);
        int cnt1 = (A - 1) / C + 1;
        int cnt2 = (B - 1) / D + 1;
        if (cnt1 + cnt2 <= K) {
            printf("%d %d\n", cnt1, cnt2);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
