#include <iostream>
using namespace std;

typedef long long ll;
ll N, K;
int M;
ll special_items[100000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        cin >> special_items[i];
    }

    int remaining = M;
    int count = 0;
    ll end = K;
    while (remaining > 0) {
        int i = M - remaining;
        while (i < M && special_items[i] <= end)
            ++i;
        if (i > M - remaining) {
            ++count;
            end += i - (M - remaining);
            remaining -= i - (M - remaining);
        } else {
            end += ((special_items[i] - end - 1) / K + 1) * K;
        }
    }
    cout << count << endl;

    return 0;
}