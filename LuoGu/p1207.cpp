#include <iostream>
using namespace std;

int N, S;

string convert(int num, int base) {
    string ans;
    while (num > 0) {
        int digit = num % base;
        num /= base;
        char ch = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        ans = ch + ans;
    }
    return ans;
}

bool is_palindrome(const string& num) {
    for (int left = 0, right = num.length() - 1; left < right; ++left, --right) {
        if (num[left] != num[right]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> S;

    int i = S + 1;
    while (N > 0) {
        int count = 0;
        for (int base = 2; base <= 10; ++base) {
            string digits = convert(i, base);
            if (is_palindrome(digits)) {
                ++count;
                if (count >= 2)
                    break;
            }
        }
        if (count >= 2) {
            cout << i << endl;
            --N;
        }
        ++i;
    }

    return 0;
}