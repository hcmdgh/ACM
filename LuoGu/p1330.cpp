#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int color[10005];
int head[10005];
int black_cnt, white_cnt;
struct Edge {
    int dest, next;
} edges[100005];
int edges_cnt;

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

bool dfs(int node, int _color) {
    if (color[node] > 0) {
        return color[node] == _color;
    } else {
        color[node] = _color;
        if (_color == 1)
            ++black_cnt;
        else
            ++white_cnt;
        for (int i = head[node]; i; i = edges[i].next) {
            int dest = edges[i].dest;
            if (!dfs(dest, 3 - _color))
                return false;
        }
        return true;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d", &N, &M) == 2) {
        memset(color, 0, sizeof(int) * (N + 1));
        memset(head, 0, sizeof(int) * (N + 1));
        edges_cnt = 0;
        for (int i = 0; i < M; ++i) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            addEdge(src, dest);
            addEdge(dest, src);
        }
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (color[i] == 0) {
                black_cnt = white_cnt = 0;
                if (dfs(i, 1)) {
                    ans += min(black_cnt, white_cnt);
                } else {
                    ans = -1;
                    break;
                }
            }
        }
        if (ans == -1)
            printf("Impossible\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
