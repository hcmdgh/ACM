#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, S, D;
struct Edge {
    int dest, weight, next;

    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
} edges[12405];
int head[2505];
int edges_cnt = 0;
priority_queue<Edge> q;
int dis[2505];
bool visited[2505];

void addEdge(int src, int dest, int weight) {
    ++edges_cnt;
    edges[edges_cnt].weight = weight;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d%d%d", &N, &M, &S, &D);
    for (int i = 0; i < M; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(src, dest, weight);
        addEdge(dest, src, weight);
    }
    memset(dis, 0x3F, sizeof(int) * (N + 1));
    dis[S] = 0;
    Edge edge;
    edge.dest = S, edge.weight = 0;
    q.emplace(edge);
    while (!q.empty()) {
        Edge top = q.top();
        q.pop();
        int node = top.dest;
        for (int i = head[node]; i; i = edges[i].next) {
            int dest = edges[i].dest;
            if (dis[node] + edges[i].weight < dis[dest]) {
                dis[dest] = dis[node] + edges[i].weight;
                if (!visited[dest]) {
                    Edge new_edge;
                    new_edge.dest = dest, new_edge.weight = dis[dest];
                    q.emplace(new_edge);
                }
            }
        }
    }
    printf("%d\n", dis[D]);

    return 0;
}
