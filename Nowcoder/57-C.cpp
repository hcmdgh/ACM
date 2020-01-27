#include <iostream>
using namespace std;

typedef long long ll;
ll weights[25];
ll X, W;
int T, N;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld%lld", &N, &X, &W);
        for (int i = 0; i < N; ++i) {
            scanf("%lld", weights + i);
        }
        max_element;
    }

    return 0;
}