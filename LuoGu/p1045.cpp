#include <iostream>
#include <cmath>
using namespace std;

const int LENGTH = 500;
int a[LENGTH], result[LENGTH];

// 计算a*b，结果存入a
void multiply(int a[], int b[]) {
    int c[LENGTH] = {0};
    for (int i = 0; i < LENGTH; ++i) {
        int carry = 0;
        for (int j = 0; i + j < LENGTH; ++j) {
            c[i + j] += b[i] * a[j] + carry;
            carry = c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    for (int i = 0; i < LENGTH; ++i)
        a[i] = c[i];
}

int main() {
    ios::sync_with_stdio(false);

    int P;
    cin >> P;

    cout << (int)(P * log10(2) + 1) << endl;

    a[0] = 2;
    result[0] = 1;
    int b = P;
    while (b > 0) {
        if (b & 1) {
            multiply(result, a);
        }
        multiply(a, a);
        b >>= 1;
    }
    --result[0];

    int index = LENGTH - 1;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 50; ++j) {
            cout << result[index];
            --index;
        }
        cout << endl;
    }

    return 0;
}