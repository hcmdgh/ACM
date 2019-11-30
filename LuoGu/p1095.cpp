#include <iostream>
#include <climits>
using namespace std;

int dp[300005];
int M, S, T;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d", &M, &S, &T) == 3) {
        dp[0] = 0;
        for (int i = 1; i <= T; ++i) {
            if (M >= 10) {
                M -= 10;
                dp[i] = dp[i - 1] + 60;
            } else {
                M += 4;
                dp[i] = dp[i - 1];
            }
        }
        int min_t = INT_MAX;
        for (int i = 1; i <= T; ++i) {
            dp[i] = max(dp[i], dp[i - 1] + 17);
            if (dp[i] >= S) {
                min_t = i;
                break;
            }
        }
        if (min_t < INT_MAX) {
            printf("Yes\n%d\n", min_t);
        } else {
            printf("No\n%d\n", dp[T]);
        }
    }

    return 0;
}