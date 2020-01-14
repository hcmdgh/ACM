#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1005;
int N;
struct Edge {
    int dest, next;
} edges[MAXN << 1];
int edges_cnt = 0;
int head[MAXN];
int nodes[MAXN];
bool visited[MAXN];
int fa[MAXN];

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

void bfs() {
    queue<int> q;
    int cnt = 0;
    q.emplace(1);
    fa[0] = fa[1] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        nodes[cnt++] = node;
        for (int i = head[node]; i; i = edges[i].next) {
            int dest = edges[i].dest;
            if (dest != fa[node]) {
                q.emplace(dest);
                fa[dest] = node;
            }
        }
    }
}

void dfs(int node, int father, int depth) {
    visited[node] = true;
    if (depth < 2) {
        for (int i = head[node]; i; i = edges[i].next) {
            int dest = edges[i].dest;
            if (dest != father) {
                dfs(dest, node, depth + 1);
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N - 1; ++i) {
        int dest;
        scanf("%d", &dest);
        addEdge(dest, i + 2);
        addEdge(i + 2, dest);
    }
    bfs();
    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        int _node = nodes[i];
        if (fa[_node])
            _node = fa[_node];
        if (fa[_node])
            _node = fa[_node];
        if (!visited[nodes[i]]) {
            dfs(_node, 0, 0);
            ++ans;
        }
    }
    printf("%d\n", ans);

    return 0;
}