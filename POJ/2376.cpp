#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> Pair;
int N, T;
Pair cows[25005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &cows[i].first, &cows[i].second);
    }
    sort(cows, cows + N);
    int cnt = 0;
    int R = 0, pos = 0;
    while (R < T) {
        int bound = R + 1;
        for (int i = pos; i < N; ++i) {
            if (cows[i].first <= bound) {
                R = max(R, cows[i].second);
            } else {
                pos = i;
                break;
            }
        }
        if (R < bound) {
            break;
        }
        ++cnt;
    }
    if (R >= T)
        printf("%d\n", cnt);
    else
        printf("-1\n");

    return 0;
}