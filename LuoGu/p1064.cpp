#include <iostream>
using namespace std;

#define MAX(a, b, c, d, e) (max(a, max(b, max(c, max(d, e)))))

int N, M;
struct Item {
    int v, w;
    int att1, att2;
} items[65];
int dp[32005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N; ++i) {
        int v, p, q;
        scanf("%d%d%d", &v, &p, &q);
        items[i].v = v;
        items[i].w = v * p;
        if (q == 0) {
            items[i].att1 = items[i].att2 = -1;
        } else {
            items[i].att1 = -2;
            if (items[q].att1 == -1) {
                items[q].att1 = i;
            } else {
                items[q].att2 = i;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        int v = items[i].v, w = items[i].w;
        int att1 = items[i].att1;
        int att2 = items[i].att2;
        if (att1 != -2) {
            for (int j = M; j >= 0; --j) {
                // way1:不选0
                // way2:选0
                // way3:选0+1
                // way4:选0+2
                // way5:选0+1+2
                int way1, way2, way3, way4, way5;
                way1 = way2 = way3 = way4 = way5 = -1;
                way1 = dp[j];
                if (j >= v) {
                    way2 = dp[j - v] + w;
                }
                if (att1 != -1 && j - v - items[att1].v >= 0) {
                    way3 = dp[j - v - items[att1].v] + w + items[att1].w;
                }
                if (att2 != -1 && j - v - items[att2].v >= 0) {
                    way4 = dp[j - v - items[att2].v] + w + items[att2].w;
                }
                if (att1 != -1 && att2 != -1 && j - v - items[att1].v - items[att2].v >= 0) {
                    way5 = dp[j - v - items[att1].v - items[att2].v] + w + items[att1].w + items[att2].w;
                }
                dp[j] = MAX(way1, way2, way3, way4, way5);
            }
        }
    }
    printf("%d\n", dp[M]);

    return 0;
}
