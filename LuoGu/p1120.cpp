#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int N;
int arr[70];
int origin_length;  // 原始木棍长度
int sticks_cnt;  // 原始木棍的数量
bool used[70];
int _next[70];  // 避免搜索重复长度的木棍，存放下一个不等长的木棍的下标

// id:正在拼第几根原始木棍
// last:上一根棍子的下标
// remain:当前原始木棍剩余拼接的长度
bool dfs(int id, int last, int remain) {
    if (remain == 0) {
        if (id >= sticks_cnt) {
            return true;
        } else {
            return dfs(id + 1, -1, origin_length);
        }
    } else {
        for (int i = last + 1; i < N; ++i) {
            if (!used[i]) {
                if (arr[i] <= remain) {
                    used[i] = true;
                    if (dfs(id, i, remain - arr[i]))
                        return true;
                    used[i] = false;
                    if (remain == arr[i] || remain == origin_length)  // 关键
                        return false;
                }
                i = _next[i];
            }
        }
    }
    return false;
}

int main() {
    int _N;
    scanf("%d", &_N);
    N = 0;
    int sum = 0;
    int max_length = 0;
    while (_N--) {
        int val;
        scanf("%d", &val);
        if (val <= 50) {
            arr[N++] = val;
            sum += val;
            max_length = max(max_length, val);
        }
    }

    sort(arr, arr + N, greater<int>());
    _next[N - 1] = N - 1;
    for (int i = N - 2; i >= 0; --i) {
        if (arr[i] == arr[i + 1]) {
            _next[i] = _next[i + 1];
        } else {
            _next[i] = i;
        }
    }
    for (origin_length = max_length; origin_length <= sum; ++origin_length) {
        if (sum % origin_length == 0) {
            sticks_cnt = sum / origin_length;
            if (dfs(1, -1, origin_length)) {
                printf("%d\n", origin_length);
                break;
            }
        }
    }

    return 0;
}
