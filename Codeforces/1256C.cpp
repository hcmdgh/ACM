#include <iostream>
using namespace std;

int N, M, D;
int lens[1005];
int bridges[1005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0; i < M; ++i) {
        scanf("%d", lens + i);
    }
    int pos = D;
    int total_len = 0;
    for (int i = 0; i < M; ++i) {
        pos += lens[i] - 1;
        pos += D;
        total_len += lens[i];
    }
    if (pos <= N) {
        printf("NO\n");
    } else {
        printf("YES\n");
        if (D + total_len - 1 >= N) {
            pos = N - 1;
            for (int i = M - 1; i >= 0; --i) {
                for (int j = 0; j < lens[i]; ++j) {
                    bridges[pos] = i + 1;
                    --pos;
                }
            }
        } else {
//            printf("way2\n");
            pos = D;
            int bridge = 0;
            int contiguous_begin = N - total_len + 1;
            while (pos <= N) {
                if (pos < contiguous_begin) {
                    contiguous_begin += lens[bridge];
                    for (int i = 0; i < lens[bridge]; ++i) {
                        bridges[pos + i - 1] = bridge + 1;
                    }
                    pos += lens[bridge] - 1;
                    ++bridge;
                } else {
                    break;
                }
                pos += D;
            }
            --contiguous_begin;
            for (int i = bridge; i < M; ++i) {
                for (int j = 0; j < lens[i]; ++j) {
                    bridges[contiguous_begin] = i + 1;
                    ++contiguous_begin;
                }
            }
        }
        printf("%d", bridges[0]);
        for (int i = 1; i < N; ++i) {
            printf(" %d", bridges[i]);
        }
        putchar('\n');
    }

    return 0;
}