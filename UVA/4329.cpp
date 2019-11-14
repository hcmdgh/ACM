#include <iostream>
#include <cstring>
using namespace std;

#define LOWBIT(x) ((x)&-(x))
typedef long long ll;
int N;
int ranks[20005];
int tree[100005];
int left_cnt[20005];

int sum(int pos) {
    int res = 0;
    while (pos > 0) {
        res += tree[pos];
        pos -= LOWBIT(pos);
    }
    return res;
}

void add(int pos) {
    while (pos <= 100000) {
        ++tree[pos];
        pos += LOWBIT(pos);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < N; ++i) {
            scanf("%d", ranks + i);
        }
        for (int i = 0; i < N; ++i) {
            add(ranks[i]);
            left_cnt[i] = sum(ranks[i] - 1);
        }
        ll ans = 0;
        memset(tree, 0, sizeof(tree));
        for (int i = N - 1; i >= 0; --i) {
            add(ranks[i]);
            int right_cnt = sum(ranks[i] - 1);
            ans += left_cnt[i] * (N - i - 1 - right_cnt) + (i - left_cnt[i]) * right_cnt;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
