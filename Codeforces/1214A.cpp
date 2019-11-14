#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int N, D, E;

int main() {
    scanf("%d%d%d", &N, &D, &E);
    int dollar = D;
    int euro = E * 5;
    int ans = INT_MAX;
    for (int i = 0; i * dollar <= N; ++i) {
        int remain = (N - i * dollar) % euro;
        ans = min(ans, remain);
    }
    printf("%d\n", ans);

    return 0;
}
