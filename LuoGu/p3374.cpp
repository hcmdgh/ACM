#include <iostream>
using namespace std;

#define LOWBIT(x) ((x)&-(x))

int N, M;
int tree[500005];

void add(int pos, int val) {
    while (pos <= N) {
        tree[pos] += val;
        pos += LOWBIT(pos);
    }
}

int query(int pos) {
    int res = 0;
    while (pos > 0) {
        res += tree[pos];
        pos -= LOWBIT(pos);
    }
    return res;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        int val;
        scanf("%d", &val);
        add(i, val);
    }
    while (M--) {
        int cmd, op1, op2;
        scanf("%d%d%d", &cmd, &op1, &op2);
        if (cmd == 1) {
            add(op1, op2);
        } else {
            int ans = query(op2) - query(op1 - 1);
            printf("%d\n", ans);
        }
    }

    return 0;
}
