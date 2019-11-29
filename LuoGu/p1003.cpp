#include <iostream>
using namespace std;

struct Carpet {
    int x, y, width, height;

    bool contains(int _x, int _y) {
        return x <= _x && _x <= x + height && y <= _y && _y <= y + width;
    }
} carpets[10005];
int N, X, Y;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d%d", &carpets[i].x, &carpets[i].y, &carpets[i].height, &carpets[i].width);
    }
    scanf("%d%d", &X, &Y);
    for (int i = N - 1; i >= 0; --i) {
        if (carpets[i].contains(X, Y)) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}