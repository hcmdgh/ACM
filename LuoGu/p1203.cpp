#include <iostream>
using namespace std;

int N;
char necklace[355];

int collect(int pos, int step) {
    char color = necklace[pos];
    int cnt = 1;
    while (cnt < N) {
        pos = (pos + step + N) % N;
        if (color == 'w') {
            color = necklace[pos];
            ++cnt;
        } else if (necklace[pos] == 'w') {
            ++cnt;
        } else if (necklace[pos] != color) {
            break;
        } else {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    scanf("%s", necklace);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int cnt1 = collect(i, 1);
        int cnt2 = collect((i-1+N)%N, -1);
        ans = max(ans, cnt1 + cnt2);
    }
    ans = min(ans, N);
    printf("%d\n", ans);

    return 0;
}
