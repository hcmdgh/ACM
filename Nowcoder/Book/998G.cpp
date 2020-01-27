#include <iostream>
#include <cmath>
using namespace std;

#define SQUARE(x) ((x) * (x))
typedef long long ll;

int T, N;
ll O, H;
typedef pair<ll, ll> Pair;

Pair find(ll beginX, ll beginY, ll width, int shape, ll pos) {
    if (width <= 1) {
        return {beginX, beginY};
    }
    ll half_width = width / 2;
    ll square = SQUARE(half_width);
    ll idx = pos / square;
    pos %= square;
    if (shape == 0) {
        if (idx == 0) {
            return find(beginX, beginY, half_width, 1, pos);
        } else if (idx == 1) {
            return find(beginX, beginY + half_width, half_width, 0, pos);
        } else if (idx == 2) {
            return find(beginX + half_width, beginY + half_width, half_width, 0, pos);
        } else {
            return find(beginX + width - 1, beginY + half_width - 1, half_width, 3, pos);
        }
    } else if (shape == 1) {
        if (idx == 0) {
            return find(beginX, beginY, half_width, 0, pos);
        } else if (idx == 1) {
            return find(beginX + half_width, beginY, half_width, 1, pos);
        } else if (idx == 2) {
            return find(beginX + half_width, beginY + half_width, half_width, 1, pos);
        } else {
            return find(beginX + half_width - 1, beginY + width - 1, half_width, 2, pos);
        }
    } else if (shape == 2) {
        if (idx == 0) {
            return find(beginX, beginY, half_width, 3, pos);
        } else if (idx == 1) {
            return find(beginX, beginY - half_width, half_width, 2, pos);
        } else if (idx == 2) {
            return find(beginX - half_width, beginY - half_width, half_width, 2, pos);
        } else {
            return find(beginX - width + 1, beginY - half_width + 1, half_width, 1, pos);
        }
    } else {
        if (idx == 0) {
            return find(beginX, beginY, half_width, 2, pos);
        } else if (idx == 1) {
            return find(beginX - half_width, beginY, half_width, 3, pos);
        } else if (idx == 2) {
            return find(beginX - half_width, beginY - half_width, half_width, 3, pos);
        } else {
            return find(beginX - half_width + 1, beginY - width + 1, half_width, 0, pos);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld%lld", &N, &H, &O);
        --H, --O;
        ll width = 1 << N;
        Pair point1 = find(0, 0, width, 0, H);
        Pair point2 = find(0, 0, width, 0, O);
        printf("point1: %lld %lld\n", point1.first, point1.second);
        printf("point2: %lld %lld\n", point2.first, point2.second);
        double dis = 10 * sqrt(SQUARE(point1.first - point2.first) + SQUARE(point1.second - point2.second));
        printf("%.0lf\n", dis);
    }

    return 0;
}