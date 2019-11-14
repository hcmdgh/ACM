#include <iostream>
#include <algorithm>
using namespace std;

int lengths[100000];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> lengths[i];
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (lengths[j] > lengths[i]) {
                    swap(lengths[i], lengths[j]);
                }
            }
        }

        if (lengths[1] - 1 <= N - 2) {
            cout << lengths[1] - 1 << endl;
        } else {
            cout << N - 2 << endl;
        }
    }

    return 0;
}