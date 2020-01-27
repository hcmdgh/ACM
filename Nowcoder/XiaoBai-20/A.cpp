#include <iostream>
using namespace std;

typedef long long ll;
ll N;
const int MOD = 1e9 + 7;
struct Matrix {
    ll matrix[2][2] = {0};

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    res.matrix[i][j] = (res.matrix[i][j] + matrix[i][k] * other.matrix[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix quick_pow(Matrix a, ll b) {
    Matrix res;
    res.matrix[0][0] = 1;
    res.matrix[0][1] = 0;
    res.matrix[1][0] = 0;
    res.matrix[1][1] = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    scanf("%lld", &N);
    Matrix raw_matrix;
    raw_matrix.matrix[0][0] = 0;
    raw_matrix.matrix[0][1] = 1;
    raw_matrix.matrix[1][0] = 1;
    raw_matrix.matrix[1][1] = 1;
    Matrix res1 = quick_pow(raw_matrix, N);
    Matrix res2 = res1 * raw_matrix;
    ll num1 = res1.matrix[0][1];
    ll num2 = res2.matrix[0][1];
    ll res = num1 * num2 % MOD;
    printf("%lld\n", res);

    return 0;
}