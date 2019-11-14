#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[1000];
int sorted_arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    memcpy(sorted_arr, arr, sizeof(int) * N);

    sort(sorted_arr, sorted_arr + N);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] != sorted_arr[i]) {
            ++cnt;
            int normal_j = -1;
            int best_j = -1;
            for (int j = i + 1; j < N; ++j) {
                if (arr[j] == sorted_arr[i]) {
                    normal_j = j;
                    if (arr[i] == sorted_arr[j]) {
                        best_j = j;
                    }
                }
            }
            if (best_j > -1) {
                swap(arr[i], arr[best_j]);
            } else {
                swap(arr[i], arr[normal_j]);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
