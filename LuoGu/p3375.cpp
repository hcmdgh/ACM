#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000005;
char s1[MAXN], s2[MAXN];
int kmp[MAXN];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%s%s", s1 + 1, s2 + 1);
    int len1 = strlen(s1 + 1);
    int len2 = strlen(s2 + 1);

    // 构建next数组
    int cur = 0;
    for (int i = 2; i <= len2; ++i) {
        while (cur > 0 && s2[i] != s2[cur + 1]) {
            cur = kmp[cur];
        }
        if (s2[cur + 1] == s2[i]) {
            ++cur;
        }
        kmp[i] = cur;
    }

    // 匹配子串
    cur = 0;
    for (int i = 1; i <= len1; ++i) {
        while (cur > 0 && s2[cur + 1] != s1[i]) {
            cur = kmp[cur];
        }
        if (s2[cur + 1] == s1[i]) {
            ++cur;
        }
        if (cur == len2) {
            printf("%d\n", i - len2 + 1);
            cur = kmp[cur];
        }
    }

    for (int i = 1; i <= len2; ++i) {
        printf("%d ", kmp[i]);
    }
    putchar('\n');

    return 0;
}
