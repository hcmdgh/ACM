#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 100;
int a[SIZE], b[SIZE];

// a + b → a
void add() {
    int carry = 0;
    for (int i = 0; i < SIZE; ++i) {
        int temp = a[i] + b[i] + carry;
        a[i] = temp % 10;
        carry = temp / 10;
    }
}

// b = n!
void factorial(int n) {
    memset(b, 0, sizeof(int) * SIZE);
    b[0] = 1;
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        for (int j = 0; j < SIZE; ++j) {
            int temp = b[j] * i + carry;
            b[j] = temp % 10;
            carry = temp / 10;
        }
    }
}

// 输出a[]
void output() {
    int begin_pos = SIZE - 1;
    while (begin_pos >= 0 && a[begin_pos] == 0)
        --begin_pos;
    if (begin_pos < 0) {
        cout << "0" << endl;
    } else {
        for (int i = begin_pos; i >= 0; --i) {
            cout << a[i];
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        factorial(i);
        add();
    }

    output();

    return 0;
}