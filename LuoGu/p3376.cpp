#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

const int MAXN = 10005, MAXM = 100005;
int head[MAXN];
struct Edge {
    int src, dest, next, cap, flow;
} edges[MAXM << 1];  // 开成边数的2倍
int edges_cnt;
int N, M, S, T;
int edge_idx[MAXN];  // 存储最短路树上每个结点的所在边
int minr[MAXN];  // 从S到各个结点的最小残量

void addEdge(int src, int dest, int cap, int flow) {
    ++edges_cnt;
    edges[edges_cnt].src = src;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].cap = cap;
    edges[edges_cnt].flow = flow;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

int maxFlow() {
    int flow = 0;
    while (true) {
        queue<int> q;
        q.emplace(S);
        memset(minr, 0, sizeof(int) * (N + 1));
        minr[S] = INT_MAX;
        while (!q.empty() && !minr[T]) {
            int node = q.front();
            q.pop();
            for (int i = head[node]; i; i = edges[i].next) {
                const Edge& edge = edges[i];
                if (!minr[edge.dest] && edge.flow < edge.cap) {
                    minr[edge.dest] = min(minr[node], edge.cap - edge.flow);
                    edge_idx[edge.dest] = i;
                    q.emplace(edge.dest);
                }
            }
        }
        if (!minr[T])
            break;
        for (int node = T; node != S; node = edges[edge_idx[node]].src) {
            int idx = edge_idx[node];
            edges[idx].flow += minr[T];
            edges[idx^1].flow -= minr[T];
        }
        flow += minr[T];
    }
    return flow;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d", &N, &M, &S, &T);
    edges_cnt = 1;
    for (int i = 0; i < M; ++i) {
        int src, dest, cap;
        scanf("%d%d%d", &src, &dest, &cap);
        addEdge(src, dest, cap, 0);
        addEdge(dest, src, 0, 0);
    }
    int ans = maxFlow();
    printf("%d\n", ans);

    return 0;
}