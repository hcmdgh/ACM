#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    long long sum = 0;
    int max_val = INT_MIN;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        sum += val;
        max_val = max(max_val, val);
    }

    if (sum % 2 == 1 || sum - max_val < max_val) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}