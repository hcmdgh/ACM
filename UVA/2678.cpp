#include <iostream>
using namespace std;

int N, S;
int prefix[100005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d", &N, &S) == 2) {
        prefix[0] = 0;
        for (int i = 1; i <= N; ++i) {
            int val;
            scanf("%d", &val);
            prefix[i] = prefix[i-1] + val;
        }
        int k = 0;
        int ans = N + 1;
        for (int i = 1; i <= N; ++i) {
            while (k + 1 < i && prefix[i] - prefix[k+1] >= S) {
                ++k;
            }
            if (prefix[i] - prefix[k] >= S)
                ans = min(ans, i - k);
        }
        if (ans <= N)
            printf("%d\n", ans);
        else
            printf("0\n");
    }

    return 0;
}
