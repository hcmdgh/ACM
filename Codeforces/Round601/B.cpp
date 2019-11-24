#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
struct Fridge {
    int idx, cost;

    bool operator<(const Fridge& other) const {
        return cost < other.cost;
    }
} fridges[2005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        int sum = 0;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &fridges[i].cost);
            sum += fridges[i].cost;
            fridges[i].idx = i;
        }
        sort(fridges + 1, fridges + 1 + N);
        if (M < N || N <= 2) {
            printf("-1\n");
        } else {
            sum <<= 1;
            int cost = fridges[1].cost + fridges[2].cost;
            sum += cost * (M - N);
            printf("%d\n", sum);
            for (int i = 1; i < N; ++i) {
                printf("%d %d\n", i, i + 1);
            }
            printf("%d %d\n", N, 1);
            for (int i = 0; i < M - N; ++i) {
                printf("%d %d\n", fridges[1].idx, fridges[2].idx);
            }
        }
    }

    return 0;
}