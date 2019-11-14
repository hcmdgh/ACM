#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int N, M;
int weights[25];
bool discard[25];
bool dp[2005];
set<int> _set;
int ans;

void dfs(int pos, int discard_cnt) {
    if (discard_cnt == M && pos == N) {
//        memset(dp, 0, sizeof(dp));
//        int cnt = 0;
        _set.clear();
        for (int i = 0; i < N; ++i) {
            if (!discard[i]) {
                for (auto iter = prev())
            }
        }
        ans = max(ans, cnt);
    } else if (discard_cnt <= M && pos < N) {
        discard[pos] = true;
        dfs(pos + 1, discard_cnt + 1);
        discard[pos] = false;
        dfs(pos + 1, discard_cnt);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", weights + i);
    }

    ans = 0;
    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}
