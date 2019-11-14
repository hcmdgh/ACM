#include <iostream>
using namespace std;

int N, Q;
bool R[100005], C[100005];
int prefix_C[100005];
int prefix_R[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &Q) == 2) {
        for (int i = 1; i <= N; ++i) {
            int val;
            scanf("%d", &val);
            R[i] = val & 1;
        }
        for (int i = 1; i <= N; ++i) {
            int val;
            scanf("%d", &val);
            C[i] = val & 1;
        }
        for (int i = 1; i <= N; ++i) {
            prefix_C[i] = prefix_C[i - 1] + C[i];
            prefix_R[i] = prefix_R[i - 1] + R[i];
        }
        while (Q--) {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            if ((prefix_R[x2] - prefix_R[x1 - 1] == 0 &&
                prefix_C[y2] - prefix_C[y1 - 1] == 0) ||
                (prefix_R[x2] - prefix_R[x1 - 1] == x2 - x1 + 1 &&
                prefix_C[y2] - prefix_C[y1 - 1] == y2 - y1 + 1)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}