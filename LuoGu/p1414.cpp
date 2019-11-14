#include <iostream>
using namespace std;

int N;
int divisor[1000005];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int val;
        scanf("%d", &val);
        for (int j = 1; j * j <= val; ++j) {
            if (val % j == 0) {
                ++divisor[j];
                if (j != val / j) {
                    ++divisor[val / j];
                }
            }
        }
    }
    int cur = 1000000;
    for (int i = 1; i <= N; ++i) {
        while (divisor[cur] < i)
            --cur;
        printf("%d\n", cur);
    }

    return 0;
}
