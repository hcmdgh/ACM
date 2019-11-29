#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1005;
int N, M;
bool droped[MAXN];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M);
        int cnt = -1;
        while (M--) {
            int num;
            scanf("%d", &num);
            if (num > 0) {
                if (cnt > -1 && num < cnt) {
                    droped[i] = true;
                }
                cnt = num;
            } else {
                cnt += num;
            }
        }
        sum += cnt;
    }
    int droped_cnt = 0;
    int groups_cnt = 0;
    for (int i = 0; i < N; ++i) {
        int _prev = (i - 1 + N) % N;
        int _next = (i + 1) % N;
        if (droped[i]) {
            ++droped_cnt;
            if (droped[_prev] && droped[_next]) {
                ++groups_cnt;
            }
        }
    }
    printf("%lld %d %d\n", sum, droped_cnt, groups_cnt);

    return 0;
}