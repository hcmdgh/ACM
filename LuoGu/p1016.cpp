#include <iostream>
#include <climits>
#include <cstdio>
using namespace std;

int main() {
    // 油箱容量：C
    // 出发点汽油价格：P
    // 起点与终点的距离：D1
    // 每升油能行驶的距离：D2
    // 加油站的数量：N
    double D1, C, D2, P;
    double distances[8], prices[8];
    int N;
    cin >> D1 >> C >> D2 >> P >> N;
    distances[0] = 0;
    prices[0] = P;
    distances[N + 1] = D1;
    prices[N + 1] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> distances[i] >> prices[i];
    }

    const double maxDistance = C * D2;  // 邮箱加满能行驶的距离
    int pos = 0;
    double cost = 0;
    double oil = 0;
    while (pos <= N) {
        double price = prices[pos];
        double distance = distances[pos];
        int i = pos + 1;
        while (i < N + 1 && prices[i] > price && distances[i] - distance <= maxDistance)
            ++i;
        if (i <= N + 1 && prices[i] <= price && distances[i] - distance <= maxDistance) {
            double amount = (distances[i] - distance) / D2;
            if (amount > oil) {
                cost += (amount - oil) * price;
                oil = 0;
            } else {
                oil -= amount;
            }
            pos = i;
        } else {
            double _distance = distances[pos + 1] - distance;
            if (_distance > maxDistance) {
                cout << "No Solution" << endl;
                return 0;
            }
            cost += (C - oil) * price;
            oil = C - _distance / D2;
            ++pos;
        }
    }

    printf("%.2f\n", cost);

    return 0;
}