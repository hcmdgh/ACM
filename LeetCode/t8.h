#include <climits>
typedef long long ll;

class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        int pos = 0;
        while (pos < length && (str[pos] == ' ' || str[pos] == '\t'))
            ++pos;
        if (pos >= length)
            return 0;
        ll num = 0;
        bool negative;
        if (str[pos] == '+') {
            negative = false;
        } else if (str[pos] == '-') {
            negative = true;
        } else if (str[pos] >= '0' && str[pos] <= '9') {
            negative = false;
            --pos;
        } else {
            return 0;
        }
        for (int i = pos + 1; i < length; ++i) {
            char ch = str[i];
            if (ch >= '0' && ch <= '9') {
                if (!negative)
                    num = num * 10 + ch - '0';
                else
                    num = num * 10 - (ch - '0');
                if (num > INT_MAX)
                    return INT_MAX;
                if (num < INT_MIN)
                    return INT_MIN;
            } else {
                break;
            }
        }
        return num;
    }
};