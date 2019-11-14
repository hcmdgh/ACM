#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T, N, M;
const int MAXN = 2005, MAXM = 6005;
struct Edge {
    int dest, next, weight;
} edges[MAXM];
int edges_cnt, head[MAXN];
bool inq[MAXN];
int dis[MAXN], cnt[MAXN];

void addEdge(int src, int dest, int weight) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].weight = weight;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

bool spfa() {
    queue<int> q;
    memset(inq, 0, N + 1);
    memset(dis, 0x3F, sizeof(int) * (N + 1));
    memset(cnt, 0, sizeof(int) * (N + 1));
    dis[1] = 0;
    q.emplace(1);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        inq[top] = false;
        for (int i = head[top]; i; i = edges[i].next) {
            const Edge& edge = edges[i];
            if (dis[top] + edge.weight < dis[edge.dest]) {
                dis[edge.dest] = dis[top] + edge.weight;
                if (!inq[edge.dest]) {
                    q.emplace(edge.dest);
                    inq[edge.dest] = true;
                    if (++cnt[edge.dest] > N)
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        edges_cnt = 0;
        memset(head, 0, sizeof(int) * (N + 1));
        for (int i = 0; i < M; ++i) {
            int src, dest, weight;
            scanf("%d%d%d", &src, &dest, &weight);
            addEdge(src, dest, weight);
            if (weight >= 0)
                addEdge(dest, src, weight);
        }
        if (spfa()) {
            printf("N0\n");
        } else {
            printf("YE5\n");
        }
    }

    return 0;
}
