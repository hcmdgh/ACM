#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> times[5000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> times[i].first >> times[i].second;
    }

    sort(times, times + N);
    int begin = times[0].first;
    int end = times[0].second;
    int max_work_time = end - begin;
    for (int i = 1; i < N; ++i) {
        if (times[i].first > end) {
            begin = times[i].first;
        }
        end = max(end, times[i].second);
        max_work_time = max(max_work_time, end - begin);
    }

    int max_interval = 0;
    end = 0;
    for (int i = 0; i < N - 1; ++i) {
        end = max(end, times[i].second);
        if (times[i + 1].first > end) {
            max_interval = max(max_interval, times[i + 1].first - end);
        }
    }

    cout << max_work_time << ' ' << max_interval << endl;

    return 0;
}