#include <iostream>
using namespace std;

int a[100001];
const int MOD = 100003;

int main() {
    int N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << 1 << endl;
        return 0;
    }

    a[0] = a[1] = 1;
    for (int i = 0; i < K - 2; ++i) {
        a[i + 2] = a[i + 1] * 2 % MOD;
    }

    for (int i = K; i <= N; ++i) {
        a[i] = 0;
        for (int j = 0; j < K; ++j) {
            a[i] += a[i - j - 1];
            a[i] %= MOD;
        }
    }

    cout << a[N] << endl;

    return 0;
}