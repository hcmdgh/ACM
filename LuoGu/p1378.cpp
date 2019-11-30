#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MIN(a, b, c, d) (min(a, min(b, min(c, d))))
#define SQUARE(x) ((x) * (x))
#define DISTANCE(x1, y1, x2, y2) (sqrt(SQUARE((x1)-(x2))+SQUARE((y1)-(y2))))

int N;
int X1, Y1, X2, Y2;
struct Point {
    int x, y;
    double radius;
} points[10];
int order[10];
const double PI = acos(-1);

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &points[i].x, &points[i].y);
        order[i] = i;
    }
    double ans = 0;
    do {
        double square = 0;
        for (int i = 0; i < N; ++i) {
            int x = points[order[i]].x;
            int y = points[order[i]].y;
            double min_radius = MIN(
                    abs(X1 - x),
                    abs(X2 - x),
                    abs(Y1 - y),
                    abs(Y2 - y)
            );
            for (int j = 0; j < i; ++j) {
                double dis = DISTANCE(x, y, points[order[j]].x, points[order[j]].y);
                double radius = points[order[j]].radius;
                if (dis <= radius) {
                    min_radius = 0;
                    break;
                }
                min_radius = min(min_radius, dis - radius);
            }
            points[order[i]].radius = min_radius;
            square += PI * SQUARE(min_radius);
        }
        ans = max(ans, square);
    } while (next_permutation(order, order + N));
    int _ans = round(abs(X1 - X2) * abs(Y1 - Y2) - ans);
    printf("%d\n", _ans);

    return 0;
}