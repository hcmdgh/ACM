#include <iostream>
using namespace std;

int N;
int arr[100005];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    long long total_cost = 0;
    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        if (arr[i] == 0)
            flag = true;
        int cost1 = abs(arr[i] - 1);
        int cost2 = abs(arr[i] + 1);
        if (cost1 <= cost2) {
            arr[i] = 1;
            total_cost += cost1;
        } else {
            arr[i] = -1;
            total_cost += cost2;
            ++cnt;
        }
    }

    if ((cnt & 1) && !flag) {
        total_cost += 2;
    }

    cout << total_cost << endl;

    return 0;
}
