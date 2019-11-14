#include <iostream>
using namespace std;

int Q;

int main() {
    ios::sync_with_stdio(false);
    cin >> Q;
    while (Q--) {
        int D, I;
        cin >> D >> I;
        int node = 1;
        int cnt = I;
        for (int i = 0; i < D - 1; ++i) {
            if (cnt & 1) {
                node <<= 1;
                cnt = (cnt + 1) >> 1;
            } else {
                node = node << 1 | 1;
                cnt >>= 1;
            }
        }
        cout << node << endl;
    }

    return 0;
}