#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int N;
const int MAXN = 100005;
typedef long long ll;
struct Edge {
    int dest, next;
} edges[MAXN << 1];
int edges_cnt;
int costs[MAXN][3];
int head[MAXN], deg[MAXN];
int sequence[MAXN];
int sequence_size;
int colors[MAXN];
ll ans;
int ans_colors[MAXN];

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

bool dfs(int node, int father) {
    sequence[++sequence_size] = node;
    bool flag = false;
    for (int i = head[node]; i; i = edges[i].next) {
        int to = edges[i].dest;
        if (to != father) {
            if (flag || !dfs(to, node))
                return false;
            flag = true;
        }
    }
    return true;
}

void dfs2(int idx) {
    if (idx > N) {
        ll cost = 0;
        for (int i = 1; i <= N; ++i) {
            cost += costs[sequence[i]][colors[i]];
        }
        if (cost < ans) {
            ans = cost;
            for (int i = 1; i <= N; ++i) {
                ans_colors[sequence[i]] = colors[i] + 1;
            }
        }
    } else {
        for (int col = 0; col < 3; ++col) {
            if (idx == 1 || (idx == 2 && colors[1] != col) || (idx > 2 && col != colors[idx-1] && col != colors[idx-2])) {
                colors[idx] = col;
                dfs2(idx + 1);
            }
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf("%d", &costs[j][i]);
            }
        }
        edges_cnt = 0;
        memset(head, 0, sizeof(int) * (N + 1));
        memset(deg, 0, sizeof(int) * (N + 1));
        for (int i = 0; i < N - 1; ++i) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            addEdge(src, dest);
            addEdge(dest, src);
            ++deg[src], ++deg[dest];
        }
        int start = 0;
        for (int i = 1; i <= N; ++i) {
            if (deg[i] == 1) {
                start = i;
                break;
            }
        }
        sequence_size = 0;
        if (!start || !dfs(start, 0)) {
            printf("-1\n");
        } else {
            ans = LLONG_MAX;
            dfs2(1);
            printf("%lld\n", ans);
            printf("%d", ans_colors[1]);
            for (int i = 2; i <= N; ++i) {
                printf(" %d", ans_colors[i]);
            }
            putchar('\n');
        }
    }

    return 0;
}
