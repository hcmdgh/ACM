#include <iostream>
using namespace std;

int segments[200000];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        int N, K;
        cin >> N >> K;
        int segment_count = 0;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            if (num & 1) {
                segments[segment_count++] = i + 1;
            }
        }

        if (segment_count < K || (segment_count - (K - 1)) % 2 == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < K - 1; ++i) {
                cout << segments[i] << ' ';
            }
            cout << N << endl;
        }
    }

    return 0;
}