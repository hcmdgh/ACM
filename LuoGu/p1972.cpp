#include <iostream>
#include <algorithm>
using namespace std;

#define LOWBIT(x) (x&-(x))

int N, M;
int arr[1000005];
struct Query {
    int begin, end, idx, ans;

    static bool cmp1(const Query& q1, const Query& q2) {
        return q1.end < q2.end;
    }

    static bool cmp2(const Query& q1, const Query& q2) {
        return q1.idx < q2.idx;
    }
} queries[1000005];
int tree[1000005];
int last_pos[1000005];

int query(int pos) {
    int res = 0;
    while (pos > 0) {
        res += tree[pos];
        pos -= LOWBIT(pos);
    }
    return res;
}

void add(int pos, int val) {
    while (pos <= N) {
        tree[pos] += val;
        pos += LOWBIT(pos);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &queries[i].begin, &queries[i].end);
        queries[i].idx = i;
    }
    sort(queries, queries + M, Query::cmp1);
    int size = 0;
    for (int q = 0; q < M; ++q) {
        int begin = queries[q].begin;
        int end = queries[q].end;
        if (end != size) {
            for (int i = size + 1; i <= end; ++i) {
                int& _last_pos = last_pos[arr[i]];
                add(i, 1);
                if (_last_pos > 0) {
                    add(_last_pos, -1);
                }
                _last_pos = i;
            }
            size = end;
        }
        queries[q].ans = query(end) - query(begin - 1);
    }
    sort(queries, queries + M, Query::cmp2);
    for (int i = 0; i < M; ++i) {
        printf("%d\n", queries[i].ans);
    }

    return 0;
}
