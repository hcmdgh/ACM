#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
typedef pair<int, int> Pair;
Pair coordinates[1005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &coordinates[i].first, &coordinates[i].second);
        }
        sort(coordinates, coordinates + N);
        bool valid = true;
        for (int i = 1; i < N; ++i) {
            if (coordinates[i].first >= coordinates[i - 1].first && coordinates[i].second >= coordinates[i - 1].second)
                ;
            else {
                valid = false;
                break;
            }
        }
        if (!valid) {
            printf("NO\n");
        } else {
            printf("YES\n");
            int curX = 0, curY = 0;
            for (int i = 0; i < N; ++i) {
                int x = coordinates[i].first;
                int y = coordinates[i].second;
                for (int j = 0; j < x - curX; ++j) {
                    putchar('R');
                }
                for (int j = 0; j < y - curY; ++j) {
                    putchar('U');
                }
                curX = x;
                curY = y;
            }
            putchar('\n');
        }
    }

    return 0;
}