#include <iostream>
#include <deque>
using namespace std;

const int SIZE = 1000000;
int N, K;
int arr[SIZE];
int ans_max[SIZE];
int ans_min[SIZE];
deque<int> dq_max;
deque<int> dq_min;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i) {
        if (!dq_max.empty() && dq_max.front() <= i - K)
            dq_max.pop_front();
        if (!dq_min.empty() && dq_min.front() <= i - K)
            dq_min.pop_front();

        int num = arr[i];
        while (!dq_max.empty() && arr[dq_max.back()] <= num) {
            dq_max.pop_back();
        }
        dq_max.emplace_back(i);

        while (!dq_min.empty() && arr[dq_min.back()] >= num) {
            dq_min.pop_back();
        }
        dq_min.emplace_back(i);

        if (i >= K - 1) {
            ans_max[i - K + 1] = arr[dq_max.front()];
            ans_min[i - K + 1] = arr[dq_min.front()];
        }
    }

    for (int i = 0; i < N - K + 1; ++i) {
        cout << ans_min[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < N - K + 1; ++i) {
        cout << ans_max[i] << ' ';
    }
    cout << endl;

    return 0;
}