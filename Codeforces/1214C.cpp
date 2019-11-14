#include <cstdio>
using namespace std;

char str[200005];
int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        char ch;
        do {
            ch = getchar();
        } while (ch != '(' && ch != ')');
        str[i] = ch;
    }
    if (N & 1) {
        printf("No\n");
    } else {
        int left = 0;
        bool flag = false;
        for (int i = 0; i < N; ++i) {
            char ch = str[i];
            if (ch == '(') {
                ++left;
            } else {
                if (left > 0) {
                    --left;
                } else {
                    if (!flag)
                        flag = true;
                    else {
                        printf("No\n");
                        return 0;
                    }
                }
            }
        }
        if (left == flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
