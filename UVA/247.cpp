#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int N, M;
char buffer1[30], buffer2[30];
map<string, int> name2idx;
string idx2name[30];
int names_cnt;
bool graph[30][30];
bool visited[30];

int getID(const string& name) {
    if (name2idx.count(name)) {
        return name2idx[name];
    } else {
        ++names_cnt;
        idx2name[names_cnt] = name;
        name2idx[name] = names_cnt;
        return names_cnt;
    }
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 1; i <= N; ++i) {
        if (graph[node][i] && graph[i][node] && !visited[i]) {
            printf(", %s", idx2name[i].c_str());
            dfs(i);
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int kase = 0;
    while (scanf("%d%d", &N, &M) == 2 && N) {
        names_cnt = 0;
        name2idx.clear();
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= N; ++i)
            graph[i][i] = true;
        for (int i = 0; i < M; ++i) {
            scanf("%s%s", buffer1, buffer2);
            graph[getID(buffer1)][getID(buffer2)] = true;
        }
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= N; ++j) {
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        if (kase)
            putchar('\n');
        printf("Calling circles for data set %d:\n", ++kase);
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                printf("%s", idx2name[i].c_str());
                dfs(i);
                putchar('\n');
            }
        }
    }

    return 0;
}
