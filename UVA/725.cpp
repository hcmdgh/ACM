#include <cstdio>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

int N;
bool used[10];
bool _used[10];
int nums[5];
vector<pair<int, int>> ans;

void dfs(int pos) {
    if (pos >= 5) {
        int num2 = nums[0] * 10000 + nums[1] * 1000 + nums[2] * 100 + nums[3] * 10 + nums[4];
        int num1 = num2 * N;
        int _num = num1;
        bool valid = true;
        memcpy(_used, used, sizeof(used));
        while (_num > 0) {
            int digit = _num % 10;
            _num /= 10;
            if (digit < 0 || digit > 9 || _used[digit]) {
                valid = false;
                break;
            }
            _used[digit] = true;
        }
        if (valid) {
            for (int i = 0; i < 10; ++i) {
                if (!_used[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans.emplace_back(pair<int, int>(num1, num2));
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            if (!used[i]) {
                used[i] = true;
                nums[pos] = i;
                dfs(pos + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    bool first = true;
    while (scanf("%d", &N) == 1 && N > 0) {
        memset(used, 0, sizeof(used));
        ans.clear();
        dfs(0);
        if (!first)
            putchar('\n');
        first = false;
        if (ans.empty()) {
            printf("There are no solutions for %d.\n", N);
        } else {
            for (auto p : ans) {
                printf("%05d / %05d = %d\n", p.first, p.second, N);
            }
        }
    }

    return 0;
}
