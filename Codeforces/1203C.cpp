#include <iostream>
using namespace std;

typedef long long ll;
ll arr[400005];
int N;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int count_divisor(ll num) {
    int cnt = 0;
    ll i = 1;
    for (; i * i < num; ++i) {
        if (num % i == 0) {
            cnt += 2;
        }
    }
    if (i * i == num)
        ++cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    ll _gcd = arr[0];
    for (int i = 1; i < N; ++i) {
        _gcd = gcd(_gcd, arr[i]);
    }

    cout << count_divisor(_gcd) << endl;

    return 0;
}
