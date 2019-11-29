#include <iostream>
#include <cstring>
using namespace std;

int P1, P2, P3;
char str[105];
char res[10005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d%d", &P1, &P2, &P3) == 3) {
        scanf("%s", str);
        int len = strlen(str);
        int res_pos = 0;
        for (int i = 0; i < len; ++i) {
            if (i < len - 1 && str[i + 1] == '-') {
                char begin_ch = str[i];
                char end_ch = str[i + 2];
                ++i;
                if (begin_ch >= end_ch) {
                    res[res_pos++] = begin_ch;
                    res[res_pos++] = '-';
                    res[res_pos++] = end_ch;
                } else {
                    res[res_pos++] = begin_ch;
                    char begin, end, step;
                    if (P3 == 1) {
                        begin = begin_ch + 1;
                        end = end_ch;
                        step = 1;
                    } else {
                        begin = end_ch - 1;
                        end = begin_ch;
                        step = -1;
                    }
                    for (char j = begin; j != end; j += step) {
                        for (int k = 0; k < P2; ++k) {
                            if (P1 == 1) {
                                res[res_pos++] = tolower(j);
                            } else if (P1 == 2) {
                                res[res_pos++] = toupper(j);
                            } else {
                                res[res_pos++] = '*';
                            }
                        }
                    }
//                    res[res_pos++] = end_ch;
                }
            } else {
                res[res_pos++] = str[i];
            }
        }
        res[res_pos] = 0;
        printf("%s\n", res);
    }

    return 0;
}