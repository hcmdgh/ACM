#include <iostream>
#include <algorithm>
using namespace std;

int N, S, A, B;
int power[5005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d", &N, &S, &A, &B);
    int cnt = 0;
    while (N--) {
        int height, _power;
        scanf("%d%d", &height, &_power);
        if (height <= A + B) {
            power[cnt++] = _power;
        }
    }
    sort(power, power + cnt);
    int ans = 0;
    for (int i = 0; i < cnt; ++i) {
        if (S < power[i])
            break;
        S -= power[i];
        ++ans;
    }
    printf("%d\n", ans);

    return 0;
}