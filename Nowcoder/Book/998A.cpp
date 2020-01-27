#include <iostream>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    for (int i = 1; i < (1 << N); ++i) {
        bool first = true;
        for (int j = 0; j < N; ++j) {
            if ((i >> j) & 1) {
                if (!first)
                    putchar(' ');
                first = false;
                printf("%d", j + 1);
            }
        }
        putchar('\n');
    }

    return 0;
}