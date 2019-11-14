#include <iostream>
using namespace std;

int fib[20];

int main() {
    int A, N, M, X;
    cin >> A >> N >> M >> X;

    fib[0] = fib[1] = 1;
    for (int i = 2; i < 20; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int N_A = fib[N - 4] + 1;
    int N_T = fib[N - 3] - 1;
    int X_A = fib[X - 3] + 1;
    int X_T = fib[X - 2] - 1;

    cout << X_A * A + X_T * (M - N_A * A) / N_T << endl;

    return 0;
}