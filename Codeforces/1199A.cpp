#include <iostream>
using namespace std;

int rains[100000];
int N, X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> X >> Y;
    for (int i = 0; i < N; ++i) {
        cin >> rains[i];
    }

    for (int i = 0; i < N; ++i) {
        bool valid = true;
        for (int j = max(0, i - X); j <= min(N - 1, i + Y); ++j) {
            if (i != j && rains[j] <= rains[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}