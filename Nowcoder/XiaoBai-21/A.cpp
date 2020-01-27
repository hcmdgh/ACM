#include <iostream>
using namespace std;

typedef long long ll;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ll x1, x2, x3, y1, y2, y3;
    scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3);
    ll _a = x1 - x2;
    ll _b = y1 - y2;
    ll _c = x1 - x3;
    ll _d = y1 - y3;
    double a = _d * 1.0 / (_a * _d - _b * _c);
    double b = -_b * 1.0 / (_a * _d - _b * _c);
    double c = -_c * 1.0 / (_a * _d - _b * _c);
    double d = _a * 1.0 / (_a * _d - _b * _c);
    double x = ((x1+x2)*(x1-x2) + (y1+y2)*(y1-y2)) / 2.0;
    double y = ((x1+x3)*(x1-x3) + (y1+y3)*(y1-y3)) / 2.0;
    double resX = a * x + b * y;
    double resY = c * x + d * y;
    printf("%.3lf %.3lf\n", resX, resY);

    return 0;
}