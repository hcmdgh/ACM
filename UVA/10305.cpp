#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool graph[105][105];
vector<int> topo_res;
int visited[105];

bool dfs(int node) {
    visited[node] = -1;
    for (int i = 1; i <= N; ++i) {
        if (graph[node][i]) {
            if (visited[i] == -1)
                return false;
            if (!visited[i] && !dfs(i))
                return false;
        }
    }
    visited[node] = 1;
    topo_res.emplace_back(node);
    return true;
}

bool topo_sort() {
    topo_res.clear();
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && !dfs(i))
            return false;
    }
    reverse(topo_res.begin(), topo_res.end());
    return true;
}

int main() {
    while (scanf("%d%d", &N, &M) == 2 && N > 0) {
        memset(graph, 0, sizeof(graph));
        while (M--) {
            int src, dest;
            scanf("%d%d", &src, &dest);
            graph[src][dest] = true;
        }
        if (topo_sort()) {
            printf("%d", topo_res[0]);
            for (int i = 1; i < N; ++i) {
                printf(" %d", topo_res[i]);
            }
            putchar('\n');
        } else {
            printf("Wrong!\n");
        }
    }

    return 0;
}
