#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define SQUARE(x) ((x) * (x))

int T, N, Q;
typedef pair<int, int> Pair;
vector<int> nets[10];
int costs[10];
Pair locations[1005];
struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
} edges[1000005], edges_tree[1005];
int fa[1005];

int findSet(int node) {
    if (node != fa[node])
        fa[node] = findSet(fa[node]);
    return fa[node];
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &Q);
        for (int i = 0; i < Q; ++i) {
            int cnt, cost;
            scanf("%d%d", &cnt, &cost);
            costs[i] = cost;
            nets[i].clear();
            while (cnt--) {
                int node;
                scanf("%d", &node);
                nets[i].emplace_back(node);
            }
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%d%d", &locations[i].first, &locations[i].second);
        }
        int edges_cnt = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                int weight = SQUARE(locations[i].first - locations[j].first)
                    + SQUARE(locations[i].second - locations[j].second);
                edges[edges_cnt].src = i;
                edges[edges_cnt].dest = j;
                edges[edges_cnt].weight = weight;
                ++edges_cnt;
            }
        }
        sort(edges, edges + edges_cnt);
        for (int i = 1; i <= N; ++i)
            fa[i] = i;
        int tree_cnt = 0;
        int min_cost = 0;
        for (int i = 0; i < edges_cnt; ++i) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            int fa_src = findSet(src);
            int fa_dest = findSet(dest);
            if (fa_src != fa_dest) {
                fa[fa_src] = fa_dest;
                edges_tree[tree_cnt] = edges[i];
                min_cost += weight;
                ++tree_cnt;
                if (tree_cnt >= N - 1)
                    break;
            }
        }

        for (int choice = 1; choice < (1 << Q); ++choice) {
            for (int i = 1; i <= N; ++i)
                fa[i] = i;
            int new_cnt = N - 1;
            int total_cost = 0;
            for (int i = 0; i < Q; ++i) {
                if (choice & (1 << i)) {
                    total_cost += costs[i];
                    int fa_src = findSet(nets[i][0]);
                    for (int j = 1; j < nets[i].size(); ++j) {
                        int fa_dest = findSet(nets[i][j]);
                        if (fa_src != fa_dest) {
                            fa[fa_dest] = fa_src;
                            --new_cnt;
                        }
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < tree_cnt; ++i) {
                int src = edges_tree[i].src;
                int dest = edges_tree[i].dest;
                int weight = edges_tree[i].weight;
                int fa_src = findSet(src);
                int fa_dest = findSet(dest);
                if (fa_src != fa_dest) {
                    fa[fa_src] = fa_dest;
                    total_cost += weight;
                    ++cnt;
                    if (cnt >= new_cnt)
                        break;
                }
            }
            min_cost = min(min_cost, total_cost);
        }

        printf("%d\n", min_cost);
        if (T)
            putchar('\n');
    }

    return 0;
}
