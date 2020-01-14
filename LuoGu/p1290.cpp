#include <iostream>
using namespace std;

typedef long long ll;
int T;
ll M, N;

bool judge(ll a, ll b) {
    if (a < b)
        swap(a, b);
    if (a % b == 0) {
        return true;
    } else {
        bool res = judge(b, a % b);
        ll cnt = a / b;
        if (res) {
            return cnt > 1;
        } else {
            return true;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &M, &N);
        if (judge(M, N)) {
            printf("Stan wins\n");
        } else {
            printf("Ollie wins\n");
        }
    }

    return 0;
}