#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int B, G, N;
    scanf("%d%d%d", &B, &G, &N);
    int ans = min(N, B) + min(G, N) - N + 1;
    printf("%d\n", ans);

    return 0;
}
