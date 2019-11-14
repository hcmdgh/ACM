#include <iostream>
using namespace std;

int V, N;
int volumes[31];
int dp[20001];

int main() {
    ios::sync_with_stdio(false);
    cin >> V >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> volumes[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= volumes[i]; --j) {
            dp[j] = max(dp[j], dp[j - volumes[i]] + volumes[i]);
        }
    }

    cout << V - dp[V] << endl;

    return 0;
}