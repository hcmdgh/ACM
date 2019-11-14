#include <iostream>
#include <string>
using namespace std;

int main() {
    string expr;
    cin >> expr;

    expr += '#';
    int length = expr.length();
    int left_co = 0, right_co = 0, left_x_co = 0, right_x_co = 0;
    bool left = true;
    int co = 0;
    bool is_x = false;
    int sign = 1;
    char x_char;
    for (int i = 0; i < length; ++i) {
        char ch = expr[i];
        if (ch == '+' || ch == '-' || ch == '#' || ch == '=') {
            if (left && is_x)
                left_x_co += co * sign;
            else if (left && !is_x)
                left_co += co * sign;
            else if (!left && is_x)
                right_x_co += co * sign;
            else
                right_co += co * sign;
            if (ch == '=')
                left = false;
            co = 0;
            is_x = false;
            sign = (ch == '-') ? -1 : 1;
        } else if (ch >= '0' && ch <= '9') {
            co = co * 10 + ch - '0';
        } else {
            is_x = true;
            x_char = ch;
        }
    }

    double result = (right_co - left_co) * 1.0 / (left_x_co - right_x_co);
    printf("%c=%.3lf\n", x_char, result);

    return 0;
}