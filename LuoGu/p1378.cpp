#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = 3.141592654;
#define SQUARE(_x) ((_x)*(_x))
#define DISTANCE(_haha1, _hehe1, _haha2, _hehe2) (sqrt(SQUARE(_haha1-_haha2) + SQUARE(_hehe1-_hehe2)))

int N, haha1, haha2, hehe1, hehe2;  // 对应x1,x2,y1,y2，坑爹的洛谷
typedef pair<int, int> Point;
Point points[10];
int orders[10];
double radiuses[10];

int main() {
    scanf("%d", &N);
    scanf("%d%d%d%d", &haha1, &hehe1, &haha2, &hehe2);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &points[i].first, &points[i].second);
    }

    for (int i = 0; i < N; ++i) {
        orders[i] = i;
    }
    double min_area = 1e9;
    do {
        for (int i = 0; i < N; ++i) {
            int idx = orders[i];
            Point& point = points[idx];
            int x = point.first;
            int y = point.second;
            double radius = min(min(abs(haha1-x), abs(haha2-x)), min(abs(hehe1-y), abs(hehe2-y)));
            for (int j = 0; j < i; ++j) {
                int _idx = orders[j];
                Point& _point = points[_idx];
                double dis = DISTANCE(x, y, _point.first, _point.second);
                radius = min(radius, max(dis - radiuses[_idx], 0.0));
            }
            radiuses[idx] = radius;
        }
        double area = abs((haha1-haha2) * (hehe1-hehe2));
        for (int i = 0; i < N; ++i) {
            area -= PI * SQUARE(radiuses[i]);
        }
        min_area = min(min_area, area);
    } while (next_permutation(orders, orders + N));
    int ans = min_area + 0.5;
    printf("%d\n", ans);

    return 0;
}
