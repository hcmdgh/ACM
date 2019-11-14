#include <iostream>
#include <iomanip>
using namespace std;

const int PERIMETER = 10000;
int N, M;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> N >> M) {
        double gap1 = PERIMETER * 1.0 / N;
        double gap2 = PERIMETER * 1.0 / (N + M);
        double cost = 0;
        for (int i = 1; i < N; ++i) {
            double pos = i * gap1;
            int temp = pos / gap2;
            double cost1 = pos - temp * gap2;
            double cost2 = (temp + 1) * gap2 - pos;
            cost += min(cost1, cost2);
        }
        cout << setprecision(20) << cost << endl;
    }

    return 0;
}
