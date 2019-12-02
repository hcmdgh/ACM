#include <iostream>
#include <algorithm>
using namespace std;

int arr[70];
int per_len;  // 每根长木棍的长度
int cnt_short;  // 短木棍的数量
int cnt_long;  // 长木棍的数量
bool used[70];  // 标记每根短木棍是否已使用过
int _next[70];  // 与当前木棍长度不同的下一根木棍的id

// idx_long:当前正在拼第几根长棍
// remain:当前长棍剩余未拼的长度
// idx_short:应该从第几根短棍开始往下找
bool dfs(int idx_long, int remain, int idx_short) {
    if (idx_long >= cnt_long) {
        return true;
    } else if (remain < 0) {
        return false;
    } else if (remain == 0) {
        return dfs(idx_long + 1, per_len, 0);
    } else {
        for (int i = idx_short; i < cnt_short && i > -1;) {
            if (!used[i]) {
                used[i] = true;
                if (dfs(idx_long, remain - arr[i], i + 1)) {
                    return true;
                }
                used[i] = false;
                if (remain == arr[i] || remain == per_len) {
                    return false;
                }
                i = _next[i];
            } else {
                ++i;
            }
        }
        return false;
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    int max_len = 0;
    int sum_len = 0;
    while (N--) {
        int len;
        scanf("%d", &len);
        if (len <= 50) {
            arr[cnt_short++] = len;
            max_len = max(max_len, len);
            sum_len += len;
        }
    }
    sort(arr, arr + cnt_short, greater<int>());
    _next[cnt_short - 1] = -1;
    for (int i = cnt_short - 2; i >= 0; --i) {
        if (arr[i] == arr[i + 1]) {
            _next[i] = _next[i + 1];
        } else {
            _next[i] = i + 1;
        }
    }
    for (per_len = max_len; per_len <= sum_len; ++per_len) {
        if (sum_len % per_len == 0) {
            cnt_long = sum_len / per_len;
            if (dfs(0, per_len, 0)) {
                printf("%d\n", per_len);
                return 0;
            }
        }
    }

    return 0;
}