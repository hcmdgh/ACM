#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int P, Q, R, S;
bool is_prime[10005];
int primes_cnt = 0;
int primes[10005], exponents[10005];

void init() {
    for (int i = 2; i * i <= 10000; ++i) {
        if (!is_prime[i]) {
            for (int j = i * 2; j <= 10000; j += i) {
                primes[j] = true;
            }
        }
    }
    for (int i = 2; i <= 10000; ++i) {
        if (!is_prime[i]) {
            primes[++primes_cnt] = i;
        }
    }
}

void add_factorial(int num, int exponent) {
    for (int i = 2; i <= num; ++i) {
        int _i = i;
        for (int j = 1; j <= primes_cnt; ++j) {
            int prime = primes[j];
            while (_i % prime == 0) {
                _i /= prime;
                exponents[j] += exponent;
            }
            if (_i <= 1)
                break;
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    init();
    while (scanf("%d%d%d%d", &P, &Q, &R, &S) == 4) {
        memset(exponents, 0, sizeof(exponents));
        add_factorial(P, 1);
        add_factorial(R-S, 1);
        add_factorial(S, 1);
        add_factorial(P-Q, -1);
        add_factorial(Q, -1);
        add_factorial(R, -1);
        double ans = 1;
        for (int i = 1; i <= primes_cnt; ++i) {
            if (exponents[i]) {
                ans *= pow(primes[i], exponents[i]);
            }
        }
        printf("%.5f\n", ans);
    }

    return 0;
}
