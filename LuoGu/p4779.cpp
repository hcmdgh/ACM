#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int N, M, S;
int head[100005];
struct Edge {
    int dest, weight, next;
} edges[200005];
int edges_cnt = 0;
int dis[100005];
struct Item {
    int node, dis;

    Item(int node, int dis) : node(node), dis(dis) {}

    bool operator<(const Item& other) const {
        return dis > other.dis;
    }
};
priority_queue<Item> q;
bool visited[100005];

void addEdge(int src, int dest, int weight) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].weight = weight;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

void dijkstra() {
    memset(dis, 0x3F, sizeof(int) * (N + 1));
    q.emplace(Item(S, 0));
    dis[S] = 0;
    while (!q.empty()) {
        Item top = q.top();
        q.pop();
        if (!visited[top.node]) {
            visited[top.node] = true;
            for (int i = head[top.node]; i; i = edges[i].next) {
                int to = edges[i].dest;
                if (dis[top.node] + edges[i].weight < dis[to]) {
                    dis[to] = dis[top.node] + edges[i].weight;
                    if (!visited[to]) {
                        q.emplace(Item(to, dis[to]));
                    }
                }
            }
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d%d", &N, &M, &S);
    for (int i = 0; i < M; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(src, dest, weight);
    }

    dijkstra();

    for (int i = 1; i <= N; ++i) {
        printf("%d ", dis[i]);
    }
    putchar('\n');

    return 0;
}
