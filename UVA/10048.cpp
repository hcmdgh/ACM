#include <iostream>
#include <cstring>
using namespace std;

int C, S, Q;
int graph[105][105];
const int INF = 0x3F3F3F3F;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int kase = 0;
    while (scanf("%d%d%d", &C, &S, &Q) == 3 && C) {
        if (kase) putchar('\n');
        printf("Case #%d\n", ++kase);
        memset(graph, 0x3F, sizeof(graph));
        for (int i = 1; i <= C; ++i)
            graph[i][i] = 0;
        for (int i = 0; i < S; ++i) {
            int src, dest, weight;
            scanf("%d%d%d", &src, &dest, &weight);
            graph[src][dest] = graph[dest][src] = weight;
        }
        for (int k = 1; k <= C; ++k) {
            for (int j = 1; j <= C; ++j) {
                for (int i = 1; i <= C; ++i) {
                    graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
                }
            }
        }
        while (Q--) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            if (graph[src][dest] < INF) {
                printf("%d\n", graph[src][dest]);
            } else {
                printf("no path\n");
            }
        }
    }

    return 0;
}
