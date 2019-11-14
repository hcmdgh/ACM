#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
int N;
ll vertexes[125];
int vcnt;
bool graph[125][125];
int dis[125][125];
const int INF = 0x3f3f3f3f;

int main() {
    scanf("%d", &N);
    vcnt = 0;
    for (int i = 0; i < N; ++i) {
        ll val;
        scanf("%I64d", &val);
        if (val > 0) {
            vertexes[vcnt] = val;
            ++vcnt;
            if (vcnt > 120) {
                printf("3\n");
                return 0;
            }
        }
    }

    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < vcnt; ++i)
        dis[i][i] = 0;
    for (int i = 0; i < vcnt - 1; ++i) {
        for (int j = i + 1; j < vcnt; ++j) {
            if (vertexes[i] & vertexes[j]) {
                graph[i][j] = graph[j][i] = true;
                dis[i][j] = dis[j][i] = 1;
            }
        }
    }

    int ans = INF;
    for (int k = 0; k < vcnt; ++k) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph[i][k] && graph[k][j]) {
                    ans = min(ans, dis[i][j] + 2);
                }
            }
        }
        for (int i = 0; i < vcnt; ++i) {
            for (int j = 0; j < vcnt; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    if (ans == INF)
        ans = -1;
    printf("%d\n", ans);

    return 0;
}
