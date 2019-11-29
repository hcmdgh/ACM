#include <iostream>
using namespace std;

int N;
int arr[105];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = N; i >= 0; --i) {
        scanf("%d", arr + i);
    }
    for (int i = N; i >= 0; --i) {
        if (arr[i]) {
            if (arr[i] == 1) {
                if (i < N)
                    putchar('+');
            } else if (arr[i] == -1) {
                putchar('-');
            } else if (arr[i] > 0) {
                if (i < N)
                    putchar('+');
                printf("%d", arr[i]);
            } else {
                printf("%d", arr[i]);
            }

            if (i > 0) {
                putchar('x');
                if (i > 1) {
                    printf("^%d", i);
                }
            } else if (abs(arr[i]) == 1) {
                putchar('1');
            }
        }
    }

    return 0;
}