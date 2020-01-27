#include <iostream>
#include <cstring>
using namespace std;

int N;
int cnt[20][30];
int _cnt[30];
char buffer[10005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", buffer);
        for (char* ch = buffer; *ch; ++ch) {
            ++cnt[i][*ch - 'A'];
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << N); ++i) {
        memset(_cnt, 0, sizeof(_cnt));
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                ++count;
                for (int k = 0; k < 26; ++k) {
                    _cnt[k] += cnt[j][k];
                }
            }
        }
        if (count > ans) {
            bool valid = true;
            for (int j = 0; j < 26; ++j) {
                if (_cnt[j] % 3 != 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans = count;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}