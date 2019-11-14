#include <iostream>
using namespace std;

int T, M;
int dp[1001];
int times[101], value[101];

int main() {
    ios::sync_with_stdio(false);
    cin >> T >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> times[i] >> value[i];
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = T; j > 0; --j) {
            if (j >= times[i]) {
                dp[j] = max(dp[j], dp[j - times[i]] + value[i]);
            }
        }
    }

    cout << dp[T] << endl;

    return 0;
}