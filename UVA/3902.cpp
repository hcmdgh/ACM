#include <iostream>
#include <cstring>
using namespace std;

int N, S, K;
int leaves[1005][1005];
int leaves_size[1005];
int nodes[1005][1005];
int nodes_size[1005];
int father[1005];
bool covered[1005];

void dfs(int node, int _father, int level) {
    father[node] = _father;
    if (nodes_size[node] == 1 && level > K) {
        leaves[level][leaves_size[level]++] = node;
        return;
    }
    int size = nodes_size[node];
    for (int i = 0; i < size; ++i) {
        int next_node = nodes[node][i];
        if (next_node != _father)
            dfs(next_node, node, level + 1);
    }
}

void dfs2(int node, int prev, int dis) {
    covered[node] = true;
    int size = nodes_size[node];
    for (int i = 0; i < size; ++i) {
        if (node != prev && dis < K)
            dfs2(nodes[node][i], node, dis + 1);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &S, &K);
        memset(leaves_size, 0, sizeof(int) * N);
        memset(nodes_size, 0, sizeof(int) * (N + 1));
        for (int i = 0; i < N - 1; ++i) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            nodes[src][nodes_size[src]++] = dest;
            nodes[dest][nodes_size[dest]++] = src;
        }
        dfs(S, -1, 0);
        memset(covered, 0, N + 1);
        int ans = 0;
        for (int level = N - 1; level > K; --level) {
            int size = leaves_size[level];
            for (int i = 0; i < size; ++i) {
                int node = leaves[level][i];
                if (!covered[node]) {
                    for (int j = 0; j < K; ++j) {
                        node = father[node];
                    }
                    dfs2(node, -1, 0);
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
