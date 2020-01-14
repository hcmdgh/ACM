#include <iostream>
using namespace std;

int N, T;
char digits[200005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &T);
    digits[0] = '0';
    scanf("%s", digits + 1);
    ++N;
    int dot = -1;
    for (int i = 0; i < N; ++i) {
        if (digits[i] == '.') {
            dot = i;
            break;
        }
    }
    if (dot == N - 1) {
        digits[dot] = 0;
        printf("%s\n", digits);
        return 0;
    }
    int next_i = -1;
    for (int i = dot + 1; i < N; ++i) {
        int digit = digits[i] - '0';
        if (digit >= 5) {
            next_i = i;
            break;
        }
    }
    if (next_i > -1) {
        int last_i = next_i + 1;
        while (next_i > dot && next_i < last_i) {
            --T;
            if (T < 0) break;
            N = next_i;
            int carry = 1;
            last_i = next_i;
            for (int j = next_i - 1; j >= 0; --j) {
                if (j != dot) {
                    int d = digits[j] - '0' + carry;
                    digits[j] = d % 10 + '0';
                    carry = d / 10;
                    if (digits[j] >= '5') {
                        next_i = j;
                    }
                }
            }
        }
    }

    digits[N] = 0;
    --N;
    while (N >= dot && (digits[N] == '0' || N == dot)) {
        digits[N] = 0;
        --N;
    }
    if (digits[0] == '0') {
        printf("%s\n", digits + 1);
    } else {
        printf("%s\n", digits);
    }

    return 0;
}