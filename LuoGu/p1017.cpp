#include <iostream>
using namespace std;

char digits[100];

int main() {
//    cout << (-1) / (-2) << endl;
//    cout << (-1) % (-2) << endl;
//    return 0;
    int N, B;
    cin >> N >> B;
    int n = N;
    int length = 0;
    while (n != 0) {
        int digit = n % B;
        n /= B;
        if (digit < 0) {
            digit -= B;
            n += 1;
        }
        digits[length] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        ++length;
    }

    cout << N << '=';
    for (int i = 0; i < length; ++i) {
        cout << digits[length - i - 1];
    }
    cout << "(base" << B << ')' << endl;

    return 0;
}