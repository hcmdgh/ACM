#include <iostream>
using namespace std;

int arr[300000];
long long sum[300000];

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    long long _sum = 0;
    for (int i = N - 1; i >= 0; --i) {
        _sum += arr[i];
        sum[i] = _sum;
    }
    int tail = N - 1;
    long long result = 0;
    for (int i = K; i > 1; --i) {
        long long max_num = sum[tail];
        int index = tail;
//        for (int j = i - 1; j <= tail; ++j) {
        for (int j = tail - 1; j >= i - 1; --j) {
            if (sum[j] > max_num) {
                index = j;
                max_num = sum[j];
            }
        }
        if (tail == N - 1) {
            result += i * sum[index];
//            cout << sum[index] << endl;
        } else {
            result += i * (sum[index] - sum[tail + 1]);
//            cout << (sum[index] - sum[tail + 1]) << endl;
        }
        tail = index - 1;
    }
    if (tail + 1 < N)
        result += sum[0] - sum[tail + 1];
    else
        result += sum[0];

    cout << result << endl;

    return 0;
}