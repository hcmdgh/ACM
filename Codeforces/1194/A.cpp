#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N, X;
        cin >> N >> X;
        cout << X * 2 << endl;
    }

    return 0;
}