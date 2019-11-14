#include <iostream>
#include <climits>
using namespace std;

int nums[200000];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, K;
        cin >> N >> K;
        for (int j = 0; j < N; ++j) {
            cin >> nums[j];
        }
        if (K == 0) {
            cout << nums[0] << endl;
            continue;
        }
        int min_gap = INT_MAX;
        int min_gap_begin = -1;
        for (int j = 0; j + K < N; ++j) {
            int gap = nums[j + K] - nums[j];
            if (gap < min_gap) {
                min_gap = gap;
                min_gap_begin = j;
            }
        }

        cout << nums[min_gap_begin] + min_gap / 2 << endl;
    }

    return 0;
}