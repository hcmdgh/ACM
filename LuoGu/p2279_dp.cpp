#include <iostream>
using namespace std;

const int MAXN = 1005;
int N;
struct Edge {
    int dest, next;
} edges[MAXN << 1];
int edges_cnt = 0;
int head[MAXN];

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
    for (int i = 0; i < N - 1; ++i) {
        int dest;
        scanf("%d", &dest);
        addEdge(dest, i + 2);
        addEdge(i + 2, dest);
    }

    return 0;
}