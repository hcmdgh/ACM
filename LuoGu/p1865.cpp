#include <iostream>
#include <cstring>
using namespace std;

int N, M;
const int MAXM = 1000000;
bool primes[MAXM + 5];
int prefix_sum[MAXM + 5];

void init() {
    memset(primes, 1, sizeof(primes));
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= MAXM; ++i) {
        if (primes[i]) {
            for (int j = i * 2; j <= MAXM; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 1; i <= MAXM; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + primes[i];
    }
}

int main() {
    init();
    scanf("%d%d", &N, &M);
    while (N--) {
        int _left, _right;
        scanf("%d%d", &_left, &_right);
        if (_left < 1 || _left > M || _right < 1 || _right > M) {
            printf("Crossing the line\n");
        } else {
            printf("%d\n", prefix_sum[_right] - prefix_sum[_left - 1]);
        }
    }

    return 0;
}
