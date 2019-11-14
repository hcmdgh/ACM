#include <iostream>
using namespace std;

typedef long long ll;
int N, M;
const int MOD = 100000000;

int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

struct Matrix {
    ll elems[4];

    Matrix(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        elems[0] = a;
        elems[1] = b;
        elems[2] = c;
        elems[3] = d;
    }

    Matrix& operator*=(const Matrix& other) {
        *this = (*this) * other;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        const ll* a = elems;
        const ll* b = other.elems;
        ll* c = res.elems;
        c[0] = (a[0]*b[0] + a[1]*b[2]) % MOD;
        c[1] = (a[0]*b[1] + a[1]*b[3]) % MOD;
        c[2] = (a[2]*b[0] + a[3]*b[2]) % MOD;
        c[3] = (a[2]*b[1] + a[3]*b[3]) % MOD;
        return res;
    }
};

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    int _gcd = gcd(N, M);
    Matrix a(0, 1, 1, 1), b(1, 0, 1, 0);
    int pow = _gcd - 1;
    while (pow > 0) {
        if (pow & 1) {
            b *= a;
        }
        a *= a;
        pow >>= 1;
    }
    ll ans = (b.elems[2] + b.elems[3]) % MOD;
    printf("%lld", ans);

    return 0;
}
