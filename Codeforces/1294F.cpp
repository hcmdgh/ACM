#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
typedef pair<int, int> Pair;
const int MAXN = 200005;
struct Edge {
    int dest, next;
} edges[MAXN << 1];
int edges_cnt = 0;
int head[MAXN];
int fa[MAXN];
int dis[MAXN];

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

Pair dfs(int node, int _fa, int _dis) {
    Pair ans = {_dis, node};
    fa[node] = _fa;
    for (int i = head[node]; i; i = edges[i].next) {
        int to = edges[i].dest;
        if (to != _fa) {
            Pair res = dfs(to, node, _dis + 1);
            ans = max(ans, res);
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N - 1; ++i) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        addEdge(src, dest);
        addEdge(dest, src);
    }
    Pair node1 = dfs(1, -1, 0);
    Pair node2 = dfs(node1.second, -1, 0);
    vector<int> diameter;
    {
        int node = node2.second;
        while (node > 0) {
            diameter.emplace_back(node);
            node = fa[node];
        }
    }
    if (diameter.size() == N) {
        printf("%d\n%d %d %d\n", N - 1, diameter[0], diameter[1], diameter.back());
    } else {
        memset(dis, -1, sizeof(dis));
        queue<int> q;
        for (int node : diameter) {
            q.emplace(node);
            dis[node] = 0;
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = head[node]; i; i = edges[i].next) {
                int to = edges[i].dest;
                if (dis[to] == -1) {
                    dis[to] = dis[node] + 1;
                    q.emplace(to);
                }
            }
        }
        Pair node3 = {-1, -1};
        for (int i = 1; i <= N; ++i) {
            node3 = max(node3, {dis[i], i});
        }
        printf("%d\n%d %d %d\n", diameter.size() - 1 + node3.first, node1.second, node2.second, node3.second);
    }

    return 0;
}