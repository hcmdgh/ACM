#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
} edges[200005];
struct Query {
    int q, id;
    ll ans;
} queries[200005];
int N, M;
int ancestor[200005];
ll cnt[200005];

bool cmp1(const Query& q1, const Query& q2) {
    return q1.q < q2.q;
}

bool cmp2(const Query& q1, const Query& q2) {
    return q1.id < q2.id;
}

int findAncestor(int node) {
    if (node == ancestor[node])
        return node;
    else
        return ancestor[node] = findAncestor(ancestor[node]);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N - 1; ++i) {
        scanf("%d%d%d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d", &queries[i].q);
        queries[i].id = i;
    }

    sort(queries, queries + M, cmp1);
    sort(edges, edges + N - 1);
    for (int i = 1; i <= N; ++i) {
        ancestor[i] = i;
        cnt[i] = 1;
    }

    int j = 0;
    ll ans = 0;
    for (int i = 0; i < M; ++i) {
        int max_weight = queries[i].q;
        for (; j < N - 1; ++j) {
            if (edges[j].weight > max_weight)
                break;
            else {
                int ancestor_src = findAncestor(edges[j].src);
                int ancestor_dest = findAncestor(edges[j].dest);

                if (ancestor_src != ancestor_dest) {
                    ans -= cnt[ancestor_src] * (cnt[ancestor_src] - 1) / 2;
                    ans -= cnt[ancestor_dest] * (cnt[ancestor_dest] - 1) / 2;
                    ancestor[ancestor_src] = ancestor_dest;
                    cnt[ancestor_dest] += cnt[ancestor_src];
                    ans += cnt[ancestor_dest] * (cnt[ancestor_dest] - 1) / 2;
                } else {
                    printf("%d %d\n", edges[j].src, edges[j].dest);
                }
            }
        }
        queries[i].ans = ans;
    }
    sort(queries, queries + M, cmp2);
    printf("%I64d", queries[0].ans);
    for (int i = 1; i < M; ++i) {
        printf(" %I64d", queries[i].ans);
    }
    putchar('\n');

    return 0;
}
