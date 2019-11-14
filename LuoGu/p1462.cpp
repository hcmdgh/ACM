#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

int N, M, B;
int cost[10005];
struct Edge {
    int dest, next, weight;
} edges[100005];
int edges_cnt = 0;
int head[10005];
int dis[10005];
bool visited[10005];
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

bool judge(int max_cost) {
    priority_queue<Item> q;
    q.emplace(Item(1, 0));
    memset(dis, 0x3F, sizeof(int) * (N + 1));
    memset(visited, 0, N + 1);
    dis[1] = 0;
    while (!q.empty()) {
        Item top = q.top();
        q.pop();
        if (!visited[top.node]) {
            visited[top.node] = true;
            for (int i = head[top.node]; i; i = edges[i].next) {
                int to = edges[i].dest;
                if (cost[to] <= max_cost) {
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
    return dis[N] < B;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d%d", &N, &M, &B);
    int begin = INT_MAX, end = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", cost + i);
        end = max(end, cost[i]);
        begin = min(begin, cost[i]);
    }
    begin = max(begin, max(cost[1], cost[N]));
    for (int i = 0; i < M; ++i) {
        int src, dest, weight;
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(src, dest, weight);
        addEdge(dest, src, weight);
    }
    int _begin = begin, _end = end;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (judge(mid)) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    if (_begin <= begin && begin <= _end) {
        printf("%d\n", begin);
    } else {
        printf("AFK\n");
    }

    return 0;
}
