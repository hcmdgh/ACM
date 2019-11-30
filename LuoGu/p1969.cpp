#include <iostream>
#include <climits>
using namespace std;

int N, arr[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    int cnt = arr[0];
    for (int i = 1; i < N; ++i) {
        if (arr[i] >= arr[i - 1]) {
            cnt += arr[i] - arr[i - 1];
        }
    }
    printf("%d\n", cnt);

    return 0;
}