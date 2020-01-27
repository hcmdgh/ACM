#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Sequence {
    int min, max;
} sequences[100005];
int N;
int min_arr[100005];
int max_arr[100005];
typedef long long ll;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) {
            int cnt;
            scanf("%d", &cnt);
            Sequence& sequence = sequences[i];
            sequence.max = INT_MIN;
            sequence.min = INT_MAX;
            for (int j = 0; j < cnt; ++j) {
                int num;
                scanf("%d", &num);
                if (sequence.min < num) {
                    sequence.min = INT_MIN;
                    sequence.max = INT_MAX;
                }
                sequence.min = min(sequence.min, num);
                sequence.max = max(sequence.max, num);
            }
            min_arr[i] = sequence.min;
            max_arr[i] = sequence.max;
        }
        sort(min_arr, min_arr + N);
        sort(max_arr, max_arr + N);
        ll res = 0;
        for (int i = 0; i < N; ++i) {
            const Sequence& sequence = sequences[i];
            int pos = lower_bound(min_arr, min_arr + N, sequence.max) - min_arr;
            res += pos;
            pos = upper_bound(max_arr, max_arr + N, sequence.min) - max_arr;
            res += N - pos;
        }
        res /= 2;
        printf("%lld\n", res);
    }

    return 0;
}