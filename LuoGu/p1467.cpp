#include <iostream>
#include <cstring>
using namespace std;

int digits[15];
bool used[15];

bool judge(int num) {
    memset(used, 0, 10);
    int _num = num;
    int digit_cnt = 0;
    while (_num > 0) {
        int digit = _num % 10;
        if (digit == 0 || used[digit]) {
            return false;
        }
        used[digit] = true;
        digits[digit_cnt] = digit;
        ++digit_cnt;
        _num /= 10;
    }
    memset(used, 0, digit_cnt);
    int pos = digit_cnt - 1;
    while (true) {
        int digit = digits[pos];
        pos = ((pos - digit) % digit_cnt + digit_cnt) % digit_cnt;
        if (used[pos])
            break;
        used[pos] = true;
    }
    for (int i = 0; i < digit_cnt; ++i) {
        if (!used[i])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int M;
    cin >> M;

    int num = M + 1;
    while (!judge(num)) {
        ++num;
    }
    cout << num << endl;

    return 0;
}
