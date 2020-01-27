#include <iostream>
using namespace std;

int N;
typedef long long ll;
ll arr[100005];
ll diff[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", arr + i);
        diff[i] = arr[i] - arr[i - 1];
    }
    ll positive = 0, negative = 0;
    for (int i = 2; i <= N; ++i) {
        if (diff[i] > 0) {
            positive += diff[i];
        } else {
            negative -= diff[i];
        }
    }
    printf("%lld\n", max(positive, negative));
    printf("%lld\n", abs(positive - negative) + 1);

    return 0;
}