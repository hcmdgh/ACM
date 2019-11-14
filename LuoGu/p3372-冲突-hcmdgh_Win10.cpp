// 洛谷P3372

#include <iostream>
using namespace std;

#define LEFT_CHILD(node) ((node) << 1)
#define RIGHT_CHILD(node) (((node) << 1) ^ 1)
typedef long long ll;
const int MAXN = 100005;

int N, M;
ll arr[MAXN];
ll tree[MAXN<<2];
ll tag[MAXN<<2];
int update_left, update_right, query_left, query_right;
ll update_val;

void buildTree(int node, int node_left, int node_right) {
    if (node_left == node_right) {
        tree[node] = arr[node_left];
    } else {
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (node_left + node_right) >> 1;
        buildTree(left_child, node_left, mid);
        buildTree(right_child, mid + 1, node_right);
        tree[node] = tree[left_child] + tree[right_child];
    }
}

void push_down(int node, int node_left, int node_right) {
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    int mid = (node_left + node_right) >> 1;
    ll& _tag = tag[node];
    tag[left_child] += _tag;
    tree[left_child] += _tag * (mid - node_left + 1);
    tag[right_child] += _tag;
    tree[right_child] += _tag * (node_right - mid);
    _tag = 0;
}

void update(int node, int node_left, int node_right) {
    int len = node_right - node_left + 1;
    if (update_left <= node_left && node_right <= update_right) {
        tree[node] += update_val * len;
        tag[node] += update_val;
    } else if (update_right >= node_left && node_right >= update_left) {
        push_down(node, node_left, node_right);
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (node_left + node_right) >> 1;
        update(left_child, node_left, mid);
        update(right_child, mid + 1, node_right);
        tree[node] = tree[left_child] + tree[right_child];
    }
}

ll query(int node, int node_left, int node_right) {
    if (query_left <= node_left && node_right <= query_right) {
        return tree[node];
    } else if (query_right < node_left || node_right < query_left) {
        return 0;
    } else {
        push_down(node, node_left, node_right);
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (node_left + node_right) >> 1;
        return query(left_child, node_left, mid) +
            query(right_child, mid + 1, node_right);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", arr + i);
    }
    buildTree(1, 1, N);
    while (M--) {
        int cmd, _left, _right;
        scanf("%d%d%d", &cmd, &_left, &_right);
        if (cmd == 1) {
            ll val;
            scanf("%lld", &val);
            update_left = _left;
            update_right = _right;
            update_val = val;
            update(1, 1, N);
        } else {
            query_left = _left;
            query_right = _right;
            ll res = query(1, 1, N);
            printf("%lld\n", res);
        }
    }

    return 0;
}
