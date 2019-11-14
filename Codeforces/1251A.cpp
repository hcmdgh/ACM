#include <iostream>
#include <cstring>
using namespace std;

int T;
char str[505];
bool correct[26];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int len = strlen(str);
        memset(correct, 0, sizeof(correct));
        int i = 0;
        while (i < len) {
            int cnt = 1;
            while (i + cnt < len && str[i + cnt] == str[i])
                ++cnt;
            if (cnt & 1) {
                correct[str[i] - 'a'] = true;
            }
            i += cnt;
        }
        for (i = 0; i < 26; ++i) {
            if (correct[i]) {
                putchar('a' + i);
            }
        }
        putchar('\n');
    }

    return 0;
}