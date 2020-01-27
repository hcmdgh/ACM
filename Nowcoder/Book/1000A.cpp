#include <iostream>
using namespace std;

int N, F;
int arr[100005];
double prefix_sum[100005];

bool judge(double avg) {
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i] - avg;
    }
    double min_sum = 0;
    for (int i = 0, j = F; j <= N; ++i, ++j) {
        min_sum = min(min_sum, prefix_sum[i]);
        if (prefix_sum[j] - min_sum >= 0) {
            return true;
        }
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &F);
    double L = 0, R = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
        R = max(R, double(arr[i]));
    }
    while (R - L > 1e-5) {
        double mid = (L + R) / 2;
        if (judge(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    printf("%d\n", int(1000 * R));

    return 0;
}