#include <iostream>
using namespace std;

int fa[100005];

int findFather(int node) {
    if (fa[node] == node)
        return node;
    else
        return fa[node] = findFather(fa[node]);
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int src, dest;
    while (scanf("%d", &src) == 1) {
        for (int i = 0; i < 100005; ++i) {
            fa[i] = i;
        }
        int ans = 0;
        while (src != -1) {
            scanf("%d", &dest);
            int fa_src = findFather(src);
            int fa_dest = findFather(dest);
            if (fa_src != fa_dest) {
                fa[fa_src] = fa_dest;
            } else {
                ++ans;
            }
            scanf("%d", &src);
        }
        printf("%d\n", ans);
    }

    return 0;
}
