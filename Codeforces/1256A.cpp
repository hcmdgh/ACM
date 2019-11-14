#include <iostream>
#include <cmath>
using namespace std;

int Q, A, B, N, S;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d%d%d", &A, &B, &N, &S);
        int L = (S - B - 1) / N + 1;
        int R = S / N;
        if (L > R || A < L || R < 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}