#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, T;
int graph[55][55];
int deg[55];
typedef pair<int, int> Pair;
vector<Pair> ans;

void dfs(int node) {
    for (int i = 1; i <= 50; ++i) {
        if (graph[node][i]) {
            --graph[node][i], --graph[i][node];
            dfs(i);
            ans.emplace_back(Pair(node, i));
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        if (kase > 1)
            putchar('\n');
        scanf("%d", &N);
        memset(graph, 0, sizeof(graph));
        memset(deg, 0, sizeof(deg));
        ans.clear();
        int start = -1;
        for (int i = 0; i < N; ++i) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            ++graph[src][dest], ++graph[dest][src];
            ++deg[src], ++deg[dest];
            start = src;
        }
        bool solved = true;
        for (int i = 1; i <= 50; ++i) {
            if (deg[i] & 1) {
                solved = false;
                break;
            }
        }
        if (solved) {
            dfs(start);
            solved = ans.size() == N && ans[0].second == ans[N-1].first;
        }
        printf("Case #%d\n", kase);
        if (solved) {
            for (int i = ans.size() - 1; i >= 0; --i) {
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        } else {
            printf("some beads may be lost\n");
        }
    }

    return 0;
}
