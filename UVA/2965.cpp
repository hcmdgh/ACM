#include <iostream>
#include <map>
using namespace std;

int N;
int bones[30];
char buffer[30];

int countBit(int val) {
    int cnt = 0;
    while (val > 0) {
        cnt += val & 1;
        val >>= 1;
    }
    return cnt;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) {
            scanf("%s", buffer);
            bones[i] = 0;
            char* ch = buffer;
            while (*ch) {
                bones[i] |= (1 << (*ch - 'A'));
                ++ch;
            }
        }

        int n1 = N >> 1;
        int n2 = N - n1;
        map<int, int> _map;
        for (int i = 0; i < (1 << n1); ++i) {
            int _xor = 0;
            for (int j = 0; j < n1; ++j) {
                if (i & (1 << j)) {
                    _xor ^= bones[j];
                }
            }
            if (!_map.count(_xor) || countBit(i) > countBit(_map[_xor])) {
                _map[_xor] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << n2); ++i) {
            int _xor = 0;
            for (int j = 0; j < n2; ++j) {
                if (i & (1 << j)) {
                    _xor ^= bones[n1 + j];
                }
            }
            if (_map.count(_xor)) {
                int choice = _map[_xor];
                int _choice = (i << n1) | choice;
                if (countBit(_choice) > countBit(ans)) {
                    ans = _choice;
                }
            }
        }
        printf("%d\n", countBit(ans));
        for (int i = 0; i < N; ++i) {
            if (ans & (1 << i)) {
                printf("%d ", i + 1);
            }
        }
        putchar('\n');
    }

    return 0;
}
