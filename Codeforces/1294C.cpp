#include <iostream>
using namespace std;

int T, N;
int ans[5];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        bool valid = false;
        for (int i = 2; i * i <= N; ++i) {
            if (N % i == 0) {
                ans[0] = i;
                N /= i;
                for (int j = i + 1; j * j <= N; ++j) {
                    if (N % j == 0) {
                        ans[1] = j;
                        ans[2] = N / j;
                        if (ans[1] < ans[2]) {
                            printf("YES\n%d %d %d\n", ans[0], ans[1], ans[2]);
                            valid = true;
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (!valid) {
            printf("NO\n");
        }
    }

    return 0;
}