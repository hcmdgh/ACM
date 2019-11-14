#include <iostream>
#include <cstring>
using namespace std;

#define LEFT_CHILD(node) ((node) << 1)
#define RIGHT_CHILD(node) (((node) << 1) ^ 1)

typedef long long ll;
const int MAXN = 200000;
const ll INF = 1LL << 62;
int M, D;
ll tree[MAXN << 2];
int size = 0;
int op_left, op_right;
ll op_val, last_query = 0;

void update(int node, int node_left, int node_right) {
    if (node_left <= op_left && op_left <= node_right) {
        if (node_left == node_right) {
            tree[node] = op_val;
            return;
        }
        int mid = (node_left + node_right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        update(left_child, node_left, mid);
        update(right_child, mid + 1, node_right);
        tree[node] = max(tree[left_child], tree[right_child]);
    }
}

ll query(int node, int node_left, int node_right) {
    if (op_left <= node_left && node_right <= op_right) {
        return tree[node];
    } else if (op_right < node_left || node_right < op_left) {
        return -INF;
    } else {
        int mid = (node_left + node_right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        ll num1 = query(left_child, node_left, mid);
        ll num2 = query(right_child, mid + 1, node_right);
        return max(num1, num2);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    memset(tree, 0x80, sizeof(tree));
    scanf("%d%d", &M, &D);
    while (M--) {
        char cmd[10];
        ll val;
        scanf("%s%lld", cmd, &val);
        if (cmd[0] == 'Q') {
            op_left = size - val + 1;
            op_right = size;
            last_query = query(1, 1, MAXN);
            printf("%lld\n", last_query);
        } else {
            op_left = ++size;
            op_val = (val + last_query) % D;
            update(1, 1, MAXN);
        }
    }

    return 0;
}
