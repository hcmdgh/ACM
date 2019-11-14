#include <iostream>
#include <algorithm>
using namespace std;

int N, S, A, B;
int power[5005];
int cnt = 0;

int main() {
    scanf("%d%d%d%d", &N, &S, &A, &B);
    while (N--) {
        int height, _power;
        scanf("%d%d", &height, &_power);
        if (height <= A + B) {
            power[cnt++] = _power;
        }
    }
    if (cnt == 0) {
        printf("0\n");
        return 0;
    }
    sort(power, power + cnt);
    int ans = 0;
    while (S - power[ans] >= 0) {
        S -= power[ans];
        ++ans;
    }
    printf("%d\n", ans);

    return 0;
}
