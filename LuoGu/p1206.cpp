#include <iostream>
#include <string>
using namespace std;

int B;

string convert(int num) {
    string ans;
    while (num > 0) {
        int digit = num % B;
        num /= B;
        char ch = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        ans = ch + ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> B;

    for (int i = 1; i <= 300; ++i) {
        int square = i * i;
        string _square = convert(square);
        bool valid = true;
        for (int left = 0, right = _square.length() - 1; left < right; ++left, --right) {
            if (_square[left] != _square[right]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << convert(i) << ' ' << _square << endl;
        }
    }

    return 0;
}