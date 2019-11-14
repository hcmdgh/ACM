#include <iostream>
#include <set>
using namespace std;

struct Fraction {
    int a, b;
    double val;

    Fraction(int a, int b) : a(a), b(b), val(a*1.0/b) {}

    bool operator<(const Fraction& other) const {
        return val < other.val;
    }
};

inline int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    set<Fraction> fractions;
    fractions.emplace(Fraction(0, 1));
    fractions.emplace(Fraction(1, 1));
    for (int b = 1; b <= N; ++b) {
        for (int a = 1; a < b; ++a) {
            if (gcd(a, b) == 1) {
                fractions.emplace(Fraction(a, b));
            }
        }
    }

    for (const Fraction& fraction : fractions) {
        cout << fraction.a << '/' << fraction.b << endl;
    }

    return 0;
}
