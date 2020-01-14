#include <iostream>
#include <cstring>
using namespace std;

int M, N, P, Q;
char raw_colors[2000][2000][50];
int colors[2000][2000][3];
int digits[100];
char buffer[200];

int char2int(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    } else {
        return ch - 'a' + 10;
    }
}

void num2hex(int num) {
//    if (num == 0) {
//        strcpy(buffer, "\\x30");
//        return;
//    }
//    int digits_cnt = 0;
//    while (num > 0) {
//        digits[digits_cnt++] = num % 10;
//        num /= 10;
//    }
//    for (int i = 0; i < digits_cnt; ++i) {
//        buffer[4 * (digits_cnt - i - 1)] = '\\';
//        buffer[4 * (digits_cnt - i - 1) + 1] = 'x';
//        buffer[4 * (digits_cnt - i - 1) + 2] = '3';
//        buffer[4 * (digits_cnt - i - 1) + 3] = digits[i] + '0';
//    }
//    buffer[4 * digits_cnt] = 0;
    sprintf(buffer, "%d", num);
    for (char *p = buffer; *p; ++p) {
        printf("\\x%x", *p);
    }
}

void read_color(const char* color_str, int& color1, int& color2, int& color3) {
    int len = strlen(color_str);
    if (len == 2) {
        color1 = color2 = color3 = char2int(color_str[1]);
    } else if (len == 4) {
        color1 = char2int(color_str[1]) * 17;
        color2 = char2int(color_str[2]) * 17;
        color3 = char2int(color_str[3]) * 17;
    } else {
        color1 = char2int(color_str[1]) * 16 + char2int(color_str[2]);
        color2 = char2int(color_str[3]) * 16 + char2int(color_str[4]);
        color3 = char2int(color_str[5]) * 16 + char2int(color_str[6]);
    }
//    printf("%d %d %d\n", color1, color2, color3);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d", &M, &N, &P, &Q);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%s", raw_colors[i][j]);
        }
    }
    N /= Q, M /= P;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int avg1 = 0, avg2 = 0, avg3 = 0;
            for (int ii = 0; ii < Q; ++ii) {
                for (int jj = 0; jj < P; ++jj) {
                    int color1, color2, color3;
                    read_color(raw_colors[i*Q+ii][j*P+jj], color1, color2, color3);
                    avg1 += color1;
                    avg2 += color2;
                    avg3 += color3;
                }
            }
            avg1 /= (P * Q), avg2 /= (P * Q), avg3 /= (P * Q);
            colors[i][j][0] = avg1;
            colors[i][j][1] = avg2;
            colors[i][j][2] = avg3;
        }
    }
    for (int i = 0; i < N; ++i) {
        int current_color1 = 0, current_color2 = 0, current_color3 = 0;
        for (int j = 0; j < M; ++j) {
            int color1 = colors[i][j][0];
            int color2 = colors[i][j][1];
            int color3 = colors[i][j][2];
            if (color1 != current_color1 || color2 != current_color2 || color3 != current_color3) {
                if (color1 == 0 && color2 == 0 && color3 == 0) {
                    printf("\\x1B\\x5B\\x30\\x6D");
                } else {
                    printf("\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B");
                    num2hex(color1);
                    printf("\\x3B");
                    num2hex(color2);
                    printf("\\x3B");
                    num2hex(color3);
                    printf("\\x6D");
                }
            }
            current_color1 = color1;
            current_color2 = color2;
            current_color3 = color3;
            printf("\\x20");
        }
        if (current_color1 || current_color2 || current_color3) {
            printf("\\x1B\\x5B\\x30\\x6D");
        }
        printf("\\x0A");
    }

    return 0;
}