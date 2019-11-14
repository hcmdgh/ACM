// 蓝书P4

#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
ll A[1000005];
ll C[1000005];
int N;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> N) {
        ll M = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            M += A[i];
        }
        M /= N;
        C[0] = 0;
        for (int i = 1; i < N; ++i) {
            C[i] = C[i-1] + M - A[i];
        }
        sort(C, C + N);
        ll x1 = C[N / 2];
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += abs(x1 - C[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
