#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int N, M;
int arr[200005];
ll sum[200005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", arr + i);
        }
        sort(arr, arr + N);
        for (int i = 0; i < N; ++i) {
            if (i < M) {
                sum[i] = arr[i];
            } else {
                sum[i] = arr[i] + sum[i - M];
            }
        }
        ll res = sum[0];
        printf("%lld", res);
        for (int i = 1; i < N; ++i) {
            res += sum[i];
            printf(" %lld", res);
        }
        putchar('\n');
    }

    return 0;
}