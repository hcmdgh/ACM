#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        long long A, B, C;
        cin >> A >> B >> C;

        cout << (A + B + C) / 2 << endl;
    }

    return 0;
}