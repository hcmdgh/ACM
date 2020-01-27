#include <iostream>
using namespace std;

int N;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    double ans;
    while (scanf("%d", &N) == 1) {
        ans = 0;
        for (int i = 1; i <= N; ++i) {
            ans += 1.0 / i;
        }
        printf("%f\n", ans);
    }

    return 0;
}