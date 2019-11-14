#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define char2idx(ch) ((ch) - 'A' + 1)
#define idx2char(idx) ('A' + (idx) - 1)

int N, M;
bool graph[30][30];
char buffer[10];
vector<char> topo_res;
int visited[30];

bool dfs(int node) {
    visited[node] = -1;
    for (int i = 1; i <= N; ++i) {
        if (graph[node][i]) {
            if (visited[i] == -1)
                return false;
            else if (visited[i] == 0 && !dfs(i))
                return false;
        }
    }
    topo_res.emplace_back(idx2char(node));
    visited[node] = 1;
    return true;
}

bool topo_sort() {
    topo_res.clear();
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        if (visited[i] == 0 && !dfs(i))
            return false;
    }
    reverse(topo_res.begin(), topo_res.end());
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        scanf("%s", buffer);
        graph[char2idx(buffer[0])][char2idx(buffer[2])] = true;
        if (topo_sort()) {
            if (topo_res.size() == N) {
                printf("Sorted sequence determined after %d relations: ", i);
                for (int j = 0; j < N; ++j) {
                    putchar(topo_res[j]);
                }
                printf(".\n");
                return 0;
            }
        } else {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");

    return 0;
}
