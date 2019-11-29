#include <iostream>
using namespace std;

char records[62505];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int cnt = 0;
    char ch;
    while ((ch = getchar()) != 'E') {
        if (ch == 'W' || ch == 'L')
            records[cnt++] = ch;
    }
    int win = 0, lose = 0;
    for (int i = 0; i < cnt; ++i) {
        if (records[i] == 'W')
            ++win;
        else
            ++lose;
        if ((win >= 11 || lose >= 11) && abs(win - lose) >= 2) {
            printf("%d:%d\n", win, lose);
            win = lose = 0;
        }
    }
    printf("%d:%d\n\n", win, lose);

    win = 0, lose = 0;
    for (int i = 0; i < cnt; ++i) {
        if (records[i] == 'W')
            ++win;
        else
            ++lose;
        if ((win >= 21 || lose >= 21) && abs(win - lose) >= 2) {
            printf("%d:%d\n", win, lose);
            win = lose = 0;
        }
    }
    printf("%d:%d\n", win, lose);

    return 0;
}