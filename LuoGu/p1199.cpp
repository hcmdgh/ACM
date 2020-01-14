#include <iostream>
#include <algorithm>
using namespace std;

int N;
int graph[505][505];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &N) == 1) {
        for (int i = 1; i <= N - 1; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                scanf("%d", &graph[i][j]);
                graph[j][i] = graph[i][j];
            }
        }
        int ans = -1;
        for (int i = 1; i <= N; ++i) {
            sort(graph[i] + 1, graph[i] + N + 1);
            ans = max(ans, graph[i][N - 1]);
        }
        printf("1\n%d\n", ans);
    }

    return 0;
}