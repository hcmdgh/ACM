#include <iostream>
using namespace std;

int T, N;
char stairs[1005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &N, stairs);
        int _left = -1, _right = -1;
        for (int i = 0; i < N; ++i) {
            if (stairs[i] == '1') {
                _left = i;
                break;
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            if (stairs[i] == '1') {
                _right = i;
                break;
            }
        }
        if (_left == -1) {
            printf("%d\n", N);
        } else if (_left == _right) {
            printf("%d\n", max(_left + 1, N - _left) << 1);
        } else {
            int ans = max(max(N + 2, (_right + 1) << 1), (N - _left) << 1);
            printf("%d\n", ans);
        }
    }

    return 0;
}
