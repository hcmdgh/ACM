#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int T, N;
int fa[15];
bool graph[15][15];
int visited[15];
int prefix_sum[15];
vector<int> topo_res;
bool matrix[15][15];

char readChar() {
    while (true) {
        char ch = getchar();
        if (ch == '.' || ch == '+' || ch == '0')
            return ch;
    }
}

int findFather(int node) {
    if (node != fa[node]) {
        fa[node] = findFather(fa[node]);
    }
    return fa[node];
}

bool dfs(int node) {
    visited[node] = -1;  // 正在访问
    for (int i = 0; i <= N; ++i) {
        if (graph[node][i]) {
            if (visited[i] == -1) {
                return false;
            } else if (!visited[i]) {
                if (!dfs(i)) {
//                    return false;
                }
            }
        }
    }
    visited[node] = 1;
    topo_res.emplace_back(node);
    return true;
}

// 拓扑排序
bool topo_sort() {
    topo_res.clear();
    memset(visited, 0, sizeof(visited));
    for (int node = 0; node <= N; ++node) {
        if (!visited[node]) {
            if (!dfs(node)) {
                return false;
            }
        }
    }
    reverse(topo_res.begin(), topo_res.end());
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i <= N; ++i) {
            fa[i] = i;
        }
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; ++j) {
                char ch = readChar();
                matrix[i][j] = ch;
                if (ch == '0') {
                    fa[j] = i - 1;
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; ++j) {
                if (matrix[i][j] == '+') {
                    int fai = findFather(i - 1);
                    int faj = findFather(j);
                    graph[fai][faj] = true;
                } else if (matrix[i][j] == '-') {
                    int fai = findFather(i - 1);
                    int faj = findFather(j);
                    graph[faj][fai] = true;
                }
            }
        }
        assert(topo_sort());
        printf("topo!\n");
        int cur = 0;
        for (int i = 0; i <= N; ++i) {
            prefix_sum[topo_res[i]] = cur++;
        }
        for (int i = 1; i <= N; ++i) {
            prefix_sum[i] = prefix_sum[findFather(i)];
            if (i > 1)
                putchar(' ');
            printf("%d", prefix_sum[i] - prefix_sum[i - 1]);
        }
        putchar('\n');
    }

    return 0;
}
