#include <iostream>
using namespace std;

int M, S, T;

int main() {
    scanf("%d%d%d", &M, &S, &T);
    int s1 = 0, s2 = 0;
    for (int t = 1; t <= T; ++t) {
        s1 += 17;
        if (M >= 10) {
            M -= 10;
            s2 += 60;
        } else {
            M += 4;
        }
        if (s2 > s1) {
            s1 = s2;
        }
        if (s1 > S) {
            printf("Yes\n%d\n", t);
            return 0;
        }
    }
    printf("No\n%d\n", s1);

    return 0;
}
