#include <iostream>
using namespace std;

int T, X, Y;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &X, &Y);
        if (X >= Y) {
            printf("YES\n");
        } else {
            if (X == 1) {
                printf("NO\n");
            } else if (X <= 3) {
                if (Y <= 3) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {
                printf("YES\n");
            }
        }
    }

    return 0;
}