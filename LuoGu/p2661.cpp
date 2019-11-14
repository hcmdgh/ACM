#include <iostream>
#include <climits>
using namespace std;

int N;
int dest[200005];
int dfn[200005];
char visited[200005];  // 0:未访问 -1:正在访问 1:已访问过
int min_length = INT_MAX;

void dfs(int node, int step) {
    if (visited[node] != 1) {
        if (visited[node] == -1) {
            min_length = min(min_length, step - dfn[node]);
        } else {
            dfn[node] = step;
            visited[node] = -1;
            dfs(dest[node], step + 1);
            visited[node] = 1;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", dest + i);
    }
    for (int i = 1; i <= N; ++i) {
        dfs(i, 0);
    }
    printf("%d\n", min_length);

    return 0;
}
