#include <iostream>
using namespace std;

int N, SUM;
int perm[12];
bool used[12];
int coefficients[12];

void dfs(int index, int sum) {
    if (sum >= SUM && index < N)
        return;
    if (index >= N) {
        if (sum == SUM) {
            for (int i = 0; i < N; ++i) {
                cout << perm[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    } else {
        for (int i = 0; i < N; ++i) {
            if (!used[i]) {
                perm[index] = i + 1;
                used[i] = true;
                dfs(index + 1, sum + coefficients[index] * perm[index]);
                used[i] = false;
            }
        }
    }
}

int calcC(int m, int n) {
    if (m - n < n)
        n = m - n;
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result = result * (m - i) / (i + 1);
    }
    return result;
}

void fill_coefficients() {
    for (int i = 0; i < (N + 1) / 2; ++i) {
        int _i = N - i;
        int _j = i + 1;
        coefficients[i] = calcC(_i + _j - 2, _i - 1);
    }
    for (int i = (N + 1) / 2; i < N; ++i) {
        coefficients[i] = coefficients[N - 1 - i];
    }
}

int main() {
    cin >> N >> SUM;

    fill_coefficients();
    dfs(0, 0);

    return 0;
}