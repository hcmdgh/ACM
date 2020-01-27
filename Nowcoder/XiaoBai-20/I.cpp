#include <iostream>
using namespace std;

int N, M;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        if (N < M) {
            swap(N, M);
        }
        if ((N >= 4 && M >= 3) || N == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}