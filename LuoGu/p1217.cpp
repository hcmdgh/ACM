#include <iostream>
using namespace std;

int A, B;
int primes[10000001];

inline bool is_palindrome(int num) {
    int _num = num;
    int temp = 0;
    while (_num > 0) {
        int digit = _num % 10;
        _num /= 10;
        temp = temp * 10 + digit;
    }
    return temp == num;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> A >> B;

    B = min(B, 9999999);
    for (int i = 2; i * i <= B; ++i) {
        if (!primes[i]) {
            for (int j = i * 2; j <= B; j += i) {
                primes[j] = true;
            }
        }
    }

    for (int i = A; i <= B; ++i) {
        if (!primes[i] && is_palindrome(i)) {
            cout << i << endl;
        }
    }

    return 0;
}