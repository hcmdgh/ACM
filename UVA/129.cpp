#include <cstdio>
#include <cstring>
using namespace std;

int N, L;
char sequence[85];
int cnt;

bool dfs(int pos) {
//    sequence[pos] = 0;
//    printf("%s\n", sequence);
//    getchar();
    ++cnt;
    if (cnt >= N) {
        sequence[pos] = 0;
        return false;
    }
    for (char ch = 'A'; ch < 'A' + L; ++ch) {
        sequence[pos] = ch;
        bool valid = true;
        for (int i = 1; i <= (pos+1) / 2; ++i) {
            bool same = true;
            for (int j = 0; j < i; ++j) {
                if (sequence[pos-j] != sequence[pos-i-j]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                valid = false;
                break;
            }
        }
        if (valid) {
            if (!dfs(pos + 1))
                return false;
        }
    }
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    while (scanf("%d%d", &N, &L) == 2 && N > 0 && L > 0) {
        cnt = -1;
        dfs(0);
        int len = strlen(sequence);
        for (int i = 0; i < len; ++i) {
            putchar(sequence[i]);
            if ((i+1) % 4 == 0 && i < len - 1) {
                if (i == 16 * 4 - 1)
                    putchar('\n');
                else
                    putchar(' ');
            }
        }
        printf("\n%d\n", len);
    }

    return 0;
}
