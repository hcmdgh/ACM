#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, L;
    cin >> L >> N;

    if (N <= 0) {
        cout << "0 0" << endl;
        return 0;
    }
    int pos;
    int max_time = INT_MIN, min_time = INT_MIN;
    for (int i = 0; i < N; ++i) {
        cin >> pos;
        max_time = max(max_time, max(pos, L + 1 - pos));
        min_time = max(min_time, min(pos, L + 1 - pos));
    }

    cout << min_time << ' ' << max_time << endl;

    return 0;
}