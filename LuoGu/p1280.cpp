#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, K;
int dp[10005];
typedef pair<int, int> Pair;
map<int, vector<int>> tasks;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; ++i) {
        int start, lasting;
        scanf("%d%d", &start, &lasting);
        tasks[start].emplace_back(lasting);
    }
    for (int i = N; i >= 1; --i) {
        if (!tasks.count(i)) {
            dp[i] = dp[i + 1] + 1;
        } else {
            auto& _tasks = tasks[i];
            dp[i] = -1;
            for (auto lasting : _tasks) {
                dp[i] = max(dp[i], dp[i + lasting]);
            }
        }
    }
    printf("%d\n", dp[1]);

    return 0;
}
