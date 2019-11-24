#include <iostream>
using namespace std;

int T, A, B;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &A, &B);
        int delta = abs(B - A);
        int five = delta / 5;
        delta %= 5;
        int res;
        if (delta == 0)
            res = five;
        else if (delta == 1 || delta == 2) {
            res = five + 1;
        } else {
            res = five + 2;
        }
        printf("%d\n", res);
    }

    return 0;
}