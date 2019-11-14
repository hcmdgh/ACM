#include <iostream>
using namespace std;

int N;
int arr[205];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        int idx = arr[0];
        bool valid = true;
        for (int i = 1; i < N; ++i) {
            idx = idx % N + 1;
            if (arr[i] != idx) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            valid = true;
            idx = arr[N - 1];
            for (int i = N - 2; i >= 0; --i) {
                idx = idx % N + 1;
                if (arr[i] != idx) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
