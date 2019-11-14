#include <iostream>
#include <string>
#include <climits>
using namespace std;

const char RGB[4] = "RGB";

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        int N, K;
        string str;
        cin >> N >> K >> str;

        int min_count = INT_MAX;
        for (int i = 0; i < N - K + 1; ++i) {
            for (int j = 0; j < 3; ++j) {
                int count = 0;
                for (int k = 0; k < K; ++k) {
                    if (str[i + k] != RGB[(k + j) % 3])
                        ++count;
                }
                min_count = min(min_count, count);
            }
        }

        cout << min_count << endl;
    }

    return 0;
}