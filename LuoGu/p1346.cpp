#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, A, B;
int head[105];
struct Edge {
    int dest, next, weight;
} edges[10005];
int edges_cnt = 0;
int dis[105];
bool visited[105];
const int INF = 0x3F3F3F3F;
struct Item {
    int node, dis;

    Item(int node, int dis) : node(node), dis(dis) {}

    bool operator<(const Item& other) const {
        return dis > other.dis;
    }
};

void addEdge(int src, int dest, int weight) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].weight = weight;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

void dijkstra() {
    priority_queue<Item> q;
    q.emplace(Item(A, 0));
    memset(dis, 0x3F, sizeof(dis));
    dis[A] = 0;
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
    scanf("%d%d%d", &N, &A, &B);
    for (int i = 1; i <= N; ++i) {
        int cnt;
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            int dest;
            scanf("%d", &dest);
            addEdge(i, dest, j > 0);
        }
    }
    dijkstra();
    if (dis[B] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dis[B]);
    }

    return 0;
}
