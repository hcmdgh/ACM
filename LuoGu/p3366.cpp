#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
} edges[200005];

int fa[5005];

int findFather(int node) {
    if (node != fa[node])
        fa[node] = findFather(fa[node]);
    return fa[node];
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    sort(edges, edges + M);
    for (int i = 1; i <= N; ++i)
        fa[i] = i;
    int cnt = 0;
    int total_length = 0;
    for (int i = 0; i < M; ++i) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        int fa_src = findFather(src), fa_dest = findFather(dest);
        if (fa_src != fa_dest) {
            fa[fa_src] = fa_dest;
            total_length += weight;
            ++cnt;
            if (cnt >= N - 1)
                break;
        }
    }
    int block = 0;
    for (int i = 1; i <= N; ++i) {
        if (fa[i] == i)
            ++block;
    }
    if (block == 1)  // 判断图是否连通
        printf("%d\n", total_length);
    else
        printf("orz\n");

    return 0;
}
