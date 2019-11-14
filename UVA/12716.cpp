#include <iostream>
using namespace std;

const int MAXN = 30000000;
int N, T;
int a_cnt[MAXN + 5];
int ans[MAXN + 5];

void init() {
    for (int c = 1; c <= MAXN >> 1; ++c) {
        for (int a = c << 1; a <= MAXN; a += c) {
            int b = a - c;
            if ((a ^ b) == c) {
                ++a_cnt[a];
            }
        }
    }
    for (int i = 1; i <= MAXN; ++i) {
        ans[i] = ans[i-1] + a_cnt[i];
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    init();
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d", &N);
        printf("Case %d: %d\n", kase, ans[N]);
    }

    return 0;
}
