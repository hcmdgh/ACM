#include <iostream>
using namespace std;

long long quick_pow(long long b, long long p, long long k) {
    long long result = 1;
    while (p > 0) {
        if (p & 1) {
            result = result * b % k;
        }
        b = b * b % k;
        p >>= 1;
    }
    return result % k;
}

int main() {
    long long B, P, K;
    cin >> B >> P >> K;

    cout << B << "^" << P << " mod " << K << "=" << quick_pow(B, P, K) << endl;

    return 0;
}