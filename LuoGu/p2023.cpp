#include <iostream>
using namespace std;

#define LEFT_CHILD(node) ((node) << 1)
#define RIGHT_CHILD(node) (((node) << 1) ^ 1)

typedef long long ll;
int N, P, M;
const int MAXN = 100005;
int arr[MAXN];
ll tree[MAXN << 2], tag_add[MAXN << 2], tag_mul[MAXN << 2];
int op_left, op_right;
ll op_val;

void buildTree(int node, int node_left, int node_right) {
    tag_add[node] = 0, tag_mul[node] = 1;
    if (node_left == node_right) {
        tree[node] = arr[node_left] % P;
    } else {
        int mid = (node_left + node_right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        buildTree(left_child, node_left, mid);
        buildTree(right_child, mid + 1, node_right);
        tree[node] = (tree[left_child] + tree[right_child]) % P;
    }
}

void push_down(int node, int node_left, int node_right) {
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    int mid = (node_left + node_right) >> 1;
    ll& _tag_add = tag_add[node];
    ll& _tag_mul = tag_mul[node];
    tree[left_child] = (tree[left_child] * _tag_mul + _tag_add * (mid - node_left + 1)) % P;
    tree[right_child] = (tree[right_child] * _tag_mul + _tag_add * (node_right - mid)) % P;
    tag_mul[left_child] = (tag_mul[left_child] * _tag_mul) % P;
    tag_mul[right_child] = (tag_mul[right_child] * _tag_mul) % P;
    tag_add[left_child] = (tag_add[left_child] * _tag_mul + _tag_add) % P;
    tag_add[right_child] = (tag_add[right_child] * _tag_mul + _tag_add) % P;
    _tag_add = 0, _tag_mul = 1;
}

ll query(int node, int node_left, int node_right) {
    if (op_left <= node_left && node_right <= op_right) {
        return tree[node] % P;
    } else if (op_right < node_left || node_right < op_left) {
        return 0;
    } else {
        push_down(node, node_left, node_right);
        int mid = (node_left + node_right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        ll q1 = query(left_child, node_left, mid);
        ll q2 = query(right_child, mid + 1, node_right);
        return (q1 + q2) % P;
    }
}

void update_add(int node, int node_left, int node_right) {
    if (op_left <= node_left && node_right <= op_right) {
        tree[node] = (tree[node] + op_val * (node_right - node_left + 1)) % P;
        tag_add[node] = (tag_add[node] + op_val) % P;
    } else if (op_right < node_left || node_right < op_left) {
        ;
    } else {
        push_down(node, node_left, node_right);
        int mid = (node_left + node_right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        update_add(left_child, node_left, mid);
        update_add(right_child, mid + 1, node_right);
        tree[node] = (tree[left_child] + tree[right_child]) % P;
    }
}

void update_mul(int node, int node_left, int node_right) {
    if (op_left <= node_left && node_right <= op_right) {
        tree[node] = (tree[node] * op_val) % P;
        tag_mul[node] = (tag_mul[node] * op_val) % P;
        tag_add[node] = (tag_add[node] * op_val) % P;
    } else if (op_right < node_left || node_right < op_left) {
        ;
    } else {
        push_down(node, node_left, node_right);
        int mid = (node_left + node_right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        update_mul(left_child, node_left, mid);
        update_mul(right_child, mid + 1, node_right);
        tree[node] = (tree[left_child] + tree[right_child]) % P;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &P);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
    }
    buildTree(1, 1, N);
    scanf("%d", &M);
    while (M--) {
        int cmd;
        scanf("%d%d%d", &cmd, &op_left, &op_right);
        if (cmd == 1) {
            scanf("%lld", &op_val);
            update_mul(1, 1, N);
        } else if (cmd == 2) {
            scanf("%lld", &op_val);
            update_add(1, 1, N);
        } else {
            ll res = query(1, 1, N);
            printf("%lld\n", res);
        }
    }

    return 0;
}
