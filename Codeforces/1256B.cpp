#include <iostream>
using namespace std;

int N, Q;
int perm[105];
int num2idx[105];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", perm + i);
            num2idx[perm[i]] = i;
        }
        int cover = -1;
        for (int num = 1; num <= N; ++num) {
            int idx = num2idx[num];
            if (idx > cover) {
                for (int i = idx - 1; i > cover; --i) {
                    perm[i + 1] = perm[i];
                    num2idx[perm[i]] = i + 1;
                }
                perm[cover + 1] = num;
                num2idx[num] = cover + 1;
                if (perm[idx] == num)
                    cover = idx;
                else
                    cover = idx - 1;
            }
        }
        printf("%d", perm[0]);
        for (int i = 1; i < N; ++i) {
            printf(" %d", perm[i]);
        }
        putchar('\n');
    }

    return 0;
}