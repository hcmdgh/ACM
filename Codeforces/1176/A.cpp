#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        long long N;
        cin >> N;
        int step = 0;
        while (N > 1 && step >= 0) {
            ++step;
            if (N % 2 == 0) {
                N /= 2;
            } else if (N % 3 == 0) {
                N = 2 * N / 3;
            } else if (N % 5 == 0) {
                N = 4 * N / 5;
            } else {
                step = -1;
            }
        }
        cout << step << endl;
    }

    return 0;
}