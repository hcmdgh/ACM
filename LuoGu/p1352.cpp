#include <iostream>
#include <climits>
using namespace std;

int N;
int happiness[6005];
struct Edge {
    int dest, next;
} edges[6005];
int head[6005];
int edges_cnt = 0;
int dp[6005][2];
bool visited[6005];

void dfs(int node) {
    if (!visited[node]) {
        visited[node] = true;
        dp[node][1] = happiness[node];
        dp[node][0] = 0;
        for (int i = head[node]; i; i = edges[i].next) {
            int dest = edges[i].dest;
            dfs(dest);
            dp[node][1] += dp[dest][0];
            dp[node][0] += max(dp[dest][0], dp[dest][1]);
        }
    }
}

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", happiness + i);
    }
    for (int i = 0; i < N - 1; ++i) {
        int L, K;
        scanf("%d%d", &L, &K);
        addEdge(K, L);
    }
    int ans = INT_MIN;
    for (int i = 1; i <= N; ++i) {
        dfs(i);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    printf("%d\n", ans);

    return 0;
}