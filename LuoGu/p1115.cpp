#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    long long sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        sum += num;
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << maxSum << endl;

    return 0;
}