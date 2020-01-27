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
        int diff = abs(A - B);
        int cnt = diff / 5;
        diff %= 5;
        if (diff == 1) {
            ++cnt;
        } else if (diff == 2) {
            ++cnt;
        } else if (diff == 3) {
            cnt += 2;
        } else if (diff == 4) {
            cnt += 2;
        }
        printf("%d\n", cnt);
    }

    return 0;
}