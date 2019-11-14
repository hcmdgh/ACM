#include <iostream>
#include <algorithm>
using namespace std;

int Q, N, R;
int arr[100005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &N, &R);
        for (int i = 0; i < N; ++i) {
            scanf("%d", arr + i);
        }
        sort(arr, arr + N);
        N = unique(arr, arr + N) - arr;
        int dis = 0;
        int ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            arr[i] -= dis;
            if (arr[i] > 0) {
                ++ans;
            }
            dis += R;
        }
        printf("%d\n", ans);
    }

    return 0;
}
