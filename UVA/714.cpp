#include <iostream>
#include <cstring>
using namespace std;

int T, M, K;
typedef long long ll;
ll arr[505];

bool judge(ll max_sum) {
    int cnt = 1;
    ll sum = 0;
    for (int i = 1; i <= M; ++i) {
        if (sum + arr[i] <= max_sum) {
            sum += arr[i];
        } else {
            ++cnt;
            sum = arr[i];
        }
    }
    return cnt <= K;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        ll begin = 0, end = 0;
        scanf("%d%d", &M, &K);
        for (int i = 1; i <= M; ++i) {
            scanf("%lld", arr + i);
            end += arr[i];
            begin = max(begin, arr[i]);
        }
        while (begin <= end) {
            ll mid = (begin + end) >> 1;
            if (judge(mid)) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        ll sum = 0;
        int remain = K;
        for (int i = M; i >= 1; --i) {
            if (sum + arr[i] <= begin && i >= remain) {
                sum += arr[i];
            } else {
                sum = arr[i];
                arr[i+1] = -arr[i+1];
                --remain;
            }
        }
        printf("%lld", arr[1]);
        for (int i = 2; i <= M; ++i) {
            if (arr[i] > 0) {
                printf(" %lld", arr[i]);
            } else {
                printf(" / %lld", -arr[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}
