#include <iostream>
using namespace std;

typedef long long ll;
int Q, N;
ll K;
char chs[1000005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%lld", &N, &K);
        scanf("%s", chs);
        int last_pos = -1;
        for (int i = 0; i < N; ++i) {
            bool ch = chs[i] == '1';
            if (!ch) {
                ll step = min(K, ll(i - last_pos - 1));
                chs[i] = '1';
                chs[i - step] = '0';
                K -= step;
                ++last_pos;
                if (K <= 0)
                    break;
            }
        }
        printf("%s\n", chs);
    }

    return 0;
}