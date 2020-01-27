#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll T, HP1, HP2, ATK1, ATK2, M;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld", &HP1, &HP2, &ATK1, &ATK2, &M);
        ll round_attack = ATK1 - M;
        ll round_lose = ATK2;
        if (round_attack <= 0) {
            if (HP2 <= ATK1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            ll round = ceil((HP2 - ATK1) * 1.0 / round_attack);
            ll remain_hp = HP1 - round * round_lose;
            if (remain_hp > 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}