#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[200000];

bool judge(int median) {
    int step = 0;
    for (int i = N / 2; i < N; ++i) {
        if (median > arr[i])
            step += median - arr[i];
        else
            break;
        if (step > K)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int low = 1, high = 2000000000;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (judge(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << high << endl;

    return 0;
}