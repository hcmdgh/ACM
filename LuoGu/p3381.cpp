#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
int N, M, S, T;
const int INF = 0x3F3F3F3F;
const int MAXN = 5005, MAXM = 100005;
struct Edge {
    int src, dest, cost, flow, cap, next;
} edges[MAXM];
int edges_cnt;
bool inq[MAXN];
int minr[MAXN], dis[MAXN], pre[MAXN];
int head[MAXN];
int flow; ll cost;

void addEdge(int src, int dest, int cost, int flow, int cap) {
    ++edges_cnt;
    edges[edges_cnt].src = src;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].cost = cost;
    edges[edges_cnt].flow = flow;
    edges[edges_cnt].cap = cap;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

bool spfa() {
    memset(dis, 0x3F, sizeof(int) * (N + 1));
    memset(inq, 0, N + 1);
    dis[S] = 0;
    minr[S] = INF;
    queue<int> q;
    q.emplace(S);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        inq[top] = false;
        for (int i = head[top]; i; i = edges[i].next) {
            const Edge& edge = edges[i];
            if (edge.flow < edge.cap && dis[top] + edge.cost < dis[edge.dest]) {
                dis[edge.dest] = dis[top] + edge.cost;
                pre[edge.dest] = i;
                minr[edge.dest] = min(minr[top], edge.cap - edge.flow);
                if (!inq[edge.dest]) {
                    q.emplace(edge.dest);
                    inq[edge.dest] = true;
                }
            }
        }
    }
    if (dis[T] == INF)
        return false;
    flow += minr[T];
    cost += (ll)dis[T] * (ll)minr[T];
    for (int node = T; node != S; node = edges[pre[node]].src) {
        edges[pre[node]].flow += minr[T];
        edges[pre[node]^1].flow -= minr[T];
    }
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d%d%d", &N, &M, &S, &T);
    edges_cnt = 1;
    for (int i = 0; i < M; ++i) {
        int src, dest, cap, cost;
        scanf("%d%d%d%d", &src, &dest, &cap, &cost);
        addEdge(src, dest, cost, 0, cap);
        addEdge(dest, src, -cost, 0, 0);
    }
    flow = 0, cost = 0;
    while (spfa());
    printf("%d %lld\n", flow, cost);

    return 0;
}
