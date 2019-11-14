#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int BASE;
const int SIZE = 200;
int a[SIZE], b[SIZE];

// 获取数组中数的位数
int getLength(const int arr[]) {
    int length = SIZE;
    while (length > 0 && arr[length - 1] == 0)
        --length;
    return length;
}

// a + a的回文 → b
void add() {
    memset(b, 0, sizeof(int) * SIZE);
    int length = getLength(a);
    int carry = 0;
    for (int i = 0; i < length; ++i) {
        int temp = a[i] + a[length - 1 - i] + carry;
        b[i] = temp % BASE;
        carry = temp / BASE;
    }
    b[length] = carry;
}

bool is_palindrome(int arr[]) {
    int length = getLength(arr);
    for (int i = 0, j = length - 1; i < j; ++i, --j) {
        if (arr[i] != arr[j])
            return false;
    }
    return true;
}

// b[] → a[]
void move() {
    memcpy(a, b, sizeof(int) * SIZE);
}

int main() {
    ios::sync_with_stdio(false);
    string num_str;
    cin >> BASE >> num_str;

    int length = num_str.length();
    for (int i = 0; i < length; ++i) {
        char digit = num_str[i];
        if (digit >= '0' && digit <= '9') {
            a[length - 1 - i] = digit - '0';
        } else {
            a[length - 1 - i] = digit - 'A' + 10;
        }
    }
    if (is_palindrome(a)) {
        cout << "STEP=0" << endl;
        return 0;
    }
    for (int step = 0; step < 30; ++step) {
        add();
        if (is_palindrome(b)) {
            cout << "STEP=" << step + 1 << endl;
            return 0;
        }
        move();
    }
    cout << "Impossible!" << endl;

    return 0;
}