#include <iostream>
#include <algorithm>
using namespace std;

#define SQUARE(x) ((x)*(x))
typedef long long ll;

int N;
int arr[100005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + N);
    ll total_x = 0, total_y = 0;
    for (int i = 0; i < (N >> 1); ++i) {
        total_x += arr[i];
    }
    for (int i = N >> 1; i < N; ++i) {
        total_y += arr[i];
    }
    ll ans = SQUARE(total_x) + SQUARE(total_y);
    printf("%I64d\n", ans);

    return 0;
}
