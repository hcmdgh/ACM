#include <iostream>
#include <cmath>
using namespace std;

int N, F;
double areas[10005];
const double PI = acos(-1.0);
const double EPSILON = 1e-5;

bool judge(double area) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cnt += areas[i] / area;
        if (cnt >= F + 1)
            return true;
    }
    return false;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &N, &F);
        double total_area = 0;
        for (int i = 0; i < N; ++i) {
            double r;
            scanf("%lf", &r);
            areas[i] = PI * r * r;
            total_area += areas[i];
        }

        double begin = 0, end = total_area / (F + 1);
        while (begin <= end) {
            double mid = begin + (end - begin) / 2;
            if (judge(mid)) {
                begin = mid + EPSILON;
            } else {
                end = mid - EPSILON;
            }
        }
        printf("%.5f\n", end);
    }

    return 0;
}
