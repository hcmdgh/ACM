#include <iostream>
using namespace std;

int N;
typedef long long ll;
ll temp[1000005];
ll ans[1000005];

int main() {
    for (ll i = 4; i <= 1000000; ++i) {
        temp[i] = ((i-1)*(i-2)/2-(i-1)/2)/2;
        ans[i] = ans[i-1] + temp[i];
    }
    while (scanf("%d", &N) == 1 && N >= 3) {
        printf("%lld\n", ans[N]);
    }

    return 0;
}
