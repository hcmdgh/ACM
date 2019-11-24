#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int arr[200005], N, T;
int pos[200005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", arr + i);
        }
        if (N < 2) {
            printf("-1\n");
        } else {
            memset(pos, 0, sizeof(pos));
            int res = INT_MAX;
            for (int i = 1; i <= N; ++i) {
                int num = arr[i];
                if (pos[num] == 0) {
                    pos[num] = i;
                } else {
                    res = min(res, i - pos[num] + 1);
                    pos[num] = i;
                }
            }
            if (res == INT_MAX)
                res = -1;
            printf("%d\n", res);
        }
    }

    return 0;
}