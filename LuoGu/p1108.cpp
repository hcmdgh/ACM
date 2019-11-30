#include <iostream>
using namespace std;

int N;
int arr[5005], len[5005], cnt[5005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
        len[i] = 1;
    }
    int max_len = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[i] < arr[j]) {
                len[i] = max(len[i], len[j] + 1);
            }
        }
        max_len = max(max_len, len[i]);
        for (int j = 1; j < i; ++j) {
            if (arr[i] < arr[j] && len[i] == len[j] + 1) {
                cnt[i] += cnt[j];
            } else if (len[i] == len[j] && arr[i] == arr[j]) {
                cnt[j] = 0;
            }
        }
        if (cnt[i] == 0)
            cnt[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (len[i] == max_len) {
            ans += cnt[i];
        }
    }
    printf("%d %d\n", max_len, ans);

    return 0;
}
