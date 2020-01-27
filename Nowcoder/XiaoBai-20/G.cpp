#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[100005];
int dp[100005], len;
int positions[100005];
int ans[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    len = 0;
    for (int i = 0; i < N; ++i) {
        int num = arr[i];
        if (len == 0 || num > arr[len - 1]) {
            dp[len] = num;
            positions[i] = len;
            ++len;
        } else {
            int pos = upper_bound(dp, dp + len, num) - dp;
            dp[pos] = num;
            positions[i] = pos;
        }
    }
    printf("%d\n", len);
    int pos = len - 1;
    for (int i = N - 1; i >= 0; --i) {
        if (positions[i] == pos) {
            ans[pos] = i + 1;
            --pos;
        }
    }
    printf("%d", ans[0]);
    for (int i = 1; i < len; ++i) {
        printf(" %d", ans[i]);
    }
    putchar('\n');

    return 0;
}