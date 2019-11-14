#include <iostream>

using namespace std;

typedef long long ll;

inline ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    ll X, Y;
    cin >> X >> Y;

    ll product = X * Y;
    int count = 0;
    for (ll i = 2; i * i <= product; ++i) {
        if (product % i == 0) {
            ll other = product / i;
            if (gcd(i, other) == X) {
                count = (i == other) ? (count + 1) : (count + 2);
            }
        }
    }
    cout << count << endl;

    return 0;
}