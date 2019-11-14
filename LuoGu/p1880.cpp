#include <iostream>
#include <climits>
using namespace std;

#define SUM(begin, end) (prefix_sum[end] - prefix_sum[(begin) - 1])

int N;
int arr[205];
int dp_max[205][205];
int dp_min[205][205];
int prefix_sum[205];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    for (int i = N + 1; i <= N << 1; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - N];
    }

    for (int len = 2; len <= N; ++len) {
        for (int i = 1; i + len - 1 <= N + N; ++i) {
            int j = i + len - 1;
            dp_max[i][j] = INT_MIN;
            dp_min[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j]);
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j]);
            }
            dp_max[i][j] += SUM(i, j);
            dp_min[i][j] += SUM(i, j);
        }
    }
    int ans_min = INT_MAX, ans_max = INT_MIN;
    for (int i = 1; i < N + 1; ++i) {
        ans_min = min(ans_min, dp_min[i][i + N - 1]);
        ans_max = max(ans_max, dp_max[i][i + N - 1]);
    }
    printf("%d\n%d\n", ans_min, ans_max);

    return 0;
}
