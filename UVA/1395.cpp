#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
} edges[10005];
int fa[105];

int findFather(int node) {
    if (node != fa[node])
        fa[node] = findFather(fa[node]);
    return fa[node];
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d", &N, &M) == 2 && (N || M)) {
        for (int i = 0; i < M; ++i) {
            scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        }
        sort(edges, edges + M);
        int last_weight = -1;
        int ans = INT_MAX;
        for (int i = 0; i < M; ++i) {
            if (edges[i].weight != last_weight) {
                last_weight = edges[i].weight;
                int cnt = 0;
                for (int j = 1; j <= N; ++j)
                    fa[j] = j;
                for (int j = i; j < M; ++j) {
                    int src = edges[j].src;
                    int dest = edges[j].dest;
                    int weight = edges[j].weight;
                    int fa_src = findFather(src), fa_dest = findFather(dest);
                    if (fa_src != fa_dest) {
                        fa[fa_src] = fa_dest;
                        ++cnt;
                        if (cnt >= N - 1) {
                            ans = min(ans, weight - edges[i].weight);
                        }
                    }
                }
            }
        }
        if (ans == INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
