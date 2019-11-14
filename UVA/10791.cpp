#include <iostream>
using namespace std;

int N;
typedef long long ll;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int kase = 0;
    while (scanf("%d", &N) == 1 && N > 0) {
        int num = N;
        ll ans = 0;
        int cnt = 0;
        if (N == 1)
            ans = 2;
        else {
            for (ll i = 2; i * i <= N; ++i) {
                int temp = 1;
                while (num % i == 0) {
                    num /= i;
                    temp *= i;
                }
                if (temp > 1) {
                    ans += temp;
                    ++cnt;
                }
            }
            if (num > 1) {
                ans += num;
                ++cnt;
            }
            if (cnt == 1) {
                ++ans;
            }
        }
        printf("Case %d: %lld\n", ++kase, ans);
    }

    return 0;
}
