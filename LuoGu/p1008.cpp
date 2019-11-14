#include <iostream>
#include <cstring>
using namespace std;

bool used[9];

bool judge(int num) {
    while (num > 0) {
        int digit = num % 10;
        num /= 10;
        if (digit == 0 || used[digit - 1])
            return false;
        else
            used[digit - 1] = true;
    }
    return true;
}

int main() {
    for (int i = 123; i < 333; ++i) {
        int num1 = i;
        int num2 = i * 2;
        int num3 = i * 3;
        memset(used, 0, 9);
        if (judge(num1) && judge(num2) && judge(num3)) {
            cout << num1 << ' ' << num2 << ' ' << num3 << endl;
        }
    }

    return 0;
}