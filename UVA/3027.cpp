#include <iostream>
#include <cstring>
using namespace std;

int N;
int fa[20005];
int dis[20005];

char readChar() {
    char ch;
    do {
        ch = getchar();
    } while (ch != 'I' && ch != 'E' && ch != 'O');
    return ch;
}

int findRoot(int node) {
    if (fa[node] == node)
        return node;
    else {
        int root = findRoot(fa[node]);
        dis[node] += dis[fa[node]];
        fa[node] = root;
        return root;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            fa[i] = i;
            dis[i] = 0;
        }
        while (true) {
            char cmd = readChar();
            if (cmd == 'I') {
                int son, father;
                scanf("%d%d", &son, &father);
                fa[son] = father;
                dis[son] = abs(father - son) % 1000;
            } else if (cmd == 'E') {
                int node;
                scanf("%d", &node);
                findRoot(node);
                printf("%d\n", dis[node]);
            } else {
                break;
            }
        }
    }

    return 0;
}
