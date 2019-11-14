#include <iostream>
#include <climits>
using namespace std;

int N;
int arr[100005];
int max_arr[100005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int max_iq = INT_MIN;
        for (int i = 0; i < N; ++i) {
            int iq;
            scanf("%d", &iq);
            arr[i] = iq;
            max_iq = max(max_iq, iq);
            max_arr[i] = max_iq;
        }
        int ans = INT_MIN;
        for (int i = 1; i < N; ++i) {
            ans = max(ans, max_arr[i-1] - arr[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}
