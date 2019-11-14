#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int N, M, S;
int head[100005];
struct Edge {
    int dest, weight, next;
} edges[500005];
int edges_cnt = 0;
int dis[100005];
bool in_queue[100005];
const int INF = 0x3f3f3f3f;

void addEdge(int src, int dest, int weight) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].weight = weight;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

void spfa() {
    memset(dis, 0x3F, sizeof(int) * (N + 1));
    queue<int> q;
    q.emplace(S);
    in_queue[S] = true;
    dis[S] = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        in_queue[top] = false;
        for (int i = head[top]; i; i = edges[i].next) {
            int to = edges[i].dest;
            if (dis[top] + edges[i].weight < dis[to]) {
                dis[to] = dis[top] + edges[i].weight;
                if (!in_queue[to]) {
                    q.emplace(to);
                    in_queue[to] = true;
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

    spfa();

    for (int i = 1; i <= N; ++i) {
        if (dis[i] >= INF)
            dis[i] = INT_MAX;
        printf("%d ", dis[i]);
    }
    putchar('\n');

    return 0;
}
