#include <iostream>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int val;
        scanf("%d", &val);
        if (i)
            putchar(' ');
        printf("%d", N + 1 - val);
    }
    putchar('\n');

    return 0;
}