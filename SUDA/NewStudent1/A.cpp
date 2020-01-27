#include <iostream>
using namespace std;

int N, M, K;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &N, &M, &K);
    int total_area = 0;
    int s = N * M;
    for (int i = 0; i < K; ++i) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
        total_area += area;
    }
    int _gcd = gcd(total_area, s);
    total_area /= _gcd;
    s /= _gcd;
    printf("%d/%d\n", total_area, s);

    return 0;
}