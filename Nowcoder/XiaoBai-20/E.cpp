#include <iostream>
using namespace std;

#define LEFT_CHILD(x) ((x) << 1)
#define RIGHT_CHILD(x) (((x) << 1) ^ 1)

int N, M;
typedef long long ll;
const int MAXN = 200005;
ll tree[MAXN << 2];
ll tag[MAXN << 2];
ll arr[MAXN];
int update_left, update_right, update_val;
int query_left, query_right;

void push_down(int node, int L, int R) {
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    int mid = (L + R) >> 1;
    if (tag[node]) {
        tag[left_child] = tag[node];
        tag[right_child] = tag[node] + (mid - L + 1);
        tree[left_child] = (2 * tag[left_child] + mid - L) * (mid - L + 1) / 2;
        tree[right_child] = (2 * tag[right_child] + R - mid - 1) * (R - mid) / 2;
    }
    tag[node] = 0;
}

void build_tree(int node, int L, int R) {
    if (L == R) {
        tree[node] = arr[L];
    } else {
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (L + R) >> 1;
        build_tree(left_child, L, mid);
        build_tree(right_child, mid + 1, R);
        tree[node] = tree[left_child] + tree[right_child];
    }
}

void update(int node, int L, int R) {
    if (update_left <= L && R <= update_right) {
        tag[node] = update_val + L - update_left;
        tree[node] = (2 * tag[node] + R - L) * (R - L + 1) / 2;
    } else if (R < update_left || update_right < L)
        ;
    else {
        push_down(node, L, R);
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (L + R) >> 1;
        update(left_child, L, mid);
        update(right_child, mid + 1, R);
        tree[node] = tree[left_child] + tree[right_child];
    }
}

ll query(int node, int L, int R) {
    if (query_left <= L && R <= query_right) {
        return tree[node];
    } else if (R < query_left || query_right < L) {
        return 0;
    } else {
        push_down(node, L, R);
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (L + R) >> 1;
        return query(left_child, L, mid) +
            query(right_child, mid + 1, R);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", arr + i);
    }
    build_tree(1, 1, N);
    while (M--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &update_left, &update_right, &update_val);
            update(1, 1, N);
        } else {
            scanf("%d%d", &query_left, &query_right);
            printf("%lld\n", query(1, 1, N));
        }
    }

    return 0;
}