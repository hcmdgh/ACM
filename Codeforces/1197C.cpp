#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[300000];
int gaps[300000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        gaps[i] = arr[i + 1] - arr[i];
    }

    sort(gaps, gaps + N - 1);

    int ans = 0;
    for (int i = 0; i < K - 1; ++i) {
        ans += gaps[N - 2 - i];
    }
    ans = arr[N - 1] - arr[0] - ans;

    cout << ans << endl;

    return 0;
}