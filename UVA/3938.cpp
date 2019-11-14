#include <iostream>
using namespace std;

#define LEFT_CHILD(node) ((node) << 1)
#define RIGHT_CHILD(node) (((node) << 1) ^ 1)

const int MAXN = 500005;
typedef long long ll;
typedef pair<int, int> Pair;
struct Node {
    ll max_prefix, max_suffix;
    Pair max_sub;
} tree[MAXN << 2];
int N, M;
ll prefix_sum[MAXN];
int query_left, query_right;

ll sum(int begin, int end) {
    return prefix_sum[end] - prefix_sum[begin - 1];
}

ll sum(const Pair& p) {
    return sum(p.first, p.second);
}

Pair better(const Pair& p1, const Pair& p2) {
    ll sum1 = sum(p1);
    ll sum2 = sum(p2);
    if (sum1 < sum2)
        return p2;
    else if (sum1 > sum2)
        return p1;
    else if (p1 < p2)
        return p1;
    else
        return p2;
}

void buildTree(int node, int node_left, int node_right) {
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    int mid = (node_left + node_right) >> 1;
    if (node_left < node_right) {
        buildTree(left_child, node_left, mid);
        buildTree(right_child, mid + 1, node_right);
        tree[node].max_sub = better(better(tree[left_child].max_sub, tree[right_child].max_sub), {tree[left_child].max_suffix, tree[right_child].max_prefix});
        ll sum1 = sum(node_left, tree[left_child].max_prefix);
        ll sum2 = sum(node_left, tree[right_child].max_prefix);
        if (sum1 >= sum2) {
            tree[node].max_prefix = tree[left_child].max_prefix;
        } else {
            tree[node].max_prefix = tree[right_child].max_prefix;
        }
        sum1 = sum(tree[right_child].max_suffix, node_right);
        sum2 = sum(tree[left_child].max_suffix, node_right);
        if (sum1 > sum2) {
            tree[node].max_suffix = tree[right_child].max_suffix;
        } else {
            tree[node].max_suffix = tree[left_child].max_suffix;
        }
    } else {
        tree[node].max_prefix = tree[node].max_suffix = node_left;
        tree[node].max_sub = {node_left, node_left};
    }
}

Pair query_prefix(int node, int node_left, int node_right) {
    int mid = (node_left + node_right) >> 1;
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    int max_prefix = tree[node].max_prefix;
    if (max_prefix <= query_right) {
        return {node_left, max_prefix};
    } else if (query_right <= mid) {
        return query_prefix(left_child, node_left, mid);
    } else {
        Pair p_left = {node_left, tree[left_child].max_prefix};
        Pair p_right = query_prefix(right_child, mid + 1, node_right);
        p_right.first = node_left;
        return better(p_left, p_right);
    }
}

Pair query_suffix(int node, int node_left, int node_right) {
    int mid = (node_left + node_right) >> 1;
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    int max_suffix = tree[node].max_suffix;
    if (query_left <= max_suffix) {
        return {max_suffix, node_right};
    } else if (query_left >= mid + 1) {
        return query_suffix(right_child, mid + 1, node_right);
    } else {
        Pair p_left = query_suffix(left_child, node_left, mid);
        p_left.second = node_right;
        Pair p_right = {tree[right_child].max_suffix, node_right};
        return better(p_left, p_right);
    }
}

Pair query(int node, int node_left, int node_right) {
    int mid = (node_left + node_right) >> 1;
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    if (query_left <= node_left && node_right <= query_right) {
        return tree[node].max_sub;
    } else if (query_right <= mid) {
        return query(left_child, node_left, mid);
    } else if (query_left >= mid + 1) {
        return query(right_child, mid + 1, node_right);
    } else {
        Pair p_left = query(left_child, node_left, mid);
        Pair p_right = query(right_child, mid + 1, node_right);
        Pair p_suffix = query_suffix(left_child, node_left, mid);
        Pair p_prefix = query_prefix(right_child, mid + 1, node_right);
        Pair p_mid = {p_suffix.first, p_prefix.second};
        return better(better(p_left, p_right), p_mid);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int kase = 0;
    while (scanf("%d%d", &N, &M) == 2) {
        prefix_sum[0] = 0;
        for (int i = 1; i <= N; ++i) {
            int val;
            scanf("%d", &val);
            prefix_sum[i] = prefix_sum[i - 1] + val;
        }
        buildTree(1, 1, N);
        printf("Case %d:\n", ++kase);
        while (M--) {
            scanf("%d%d", &query_left, &query_right);
            Pair ans = query(1, 1, N);
            printf("%d %d\n", ans.first, ans.second);
        }
    }

    return 0;
}
