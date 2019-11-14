#include <iostream>
using namespace std;

int N, M, Q;
int _time[205];
int graph[205][205];
const int INF = 0x3F3F3F3F;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", _time + i);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j)
                graph[i][j] = INF;
        }
    }
    for (int i = 0; i < M; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        graph[src][dest] = graph[dest][src] = weight;
    }
    scanf("%d", &Q);
    int pos = 0;
    while (Q--) {
        int src, dest, t;
        scanf("%d%d%d", &src, &dest, &t);
        while (pos < N && _time[pos] <= t) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (graph[i][pos] + graph[pos][j] < graph[i][j]) {
                        graph[i][j] = graph[i][pos] + graph[pos][j];
                    }
                }
            }
            ++pos;
        }
        if (_time[src] > t || _time[dest] > t || graph[src][dest] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", graph[src][dest]);
        }
    }

    return 0;
}
