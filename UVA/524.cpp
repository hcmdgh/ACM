#include <cstdio>
#include <cstring>
using namespace std;

bool is_prime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int N;
int nums[20];
bool used[20];

void dfs(int pos) {
    if (pos >= N) {
        if (is_prime(nums[0] + nums[N - 1])) {
            printf("%d", nums[0]);
            for (int i = 1; i < N; ++i) {
                printf(" %d", nums[i]);
            }
            putchar('\n');
        }
    } else {
        for (int i = 2; i <= N; ++i) {
            if (!used[i] && is_prime(i + nums[pos-1])) {
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
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int Q = 0;
    while (scanf("%d", &N) == 1) {
        memset(used, 0, sizeof(used));
        nums[0] = 1;
        if (Q > 0)
            putchar('\n');
        printf("Case %d:\n", ++Q);
        dfs(1);
    }

    return 0;
}
