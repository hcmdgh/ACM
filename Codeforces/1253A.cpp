#include <iostream>
using namespace std;

int T, N;
int a[100005], b[100005], c[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d", b + i);
        }
        for (int i = 0; i < N; ++i) {
            c[i] = b[i] - a[i];
        }
        int pos = 0;
        while (pos < N && c[pos] == 0) {
            ++pos;
        }
        if (pos >= N) {
            printf("YES\n");
        } else {
            int val = c[pos];
            if (val < 0) {
                printf("NO\n");
            } else {
                while (pos < N && c[pos] == val) {
                    ++pos;
                }
                while (pos < N && c[pos] == 0) {
                    ++pos;
                }
                if (pos >= N) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            }
        }
    }

    return 0;
}