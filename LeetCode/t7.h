#include <climits>
#include <cmath>
typedef long long ll;

class Solution {
public:
    int reverse(int x) {
        ll num = x;
        bool negative = num < 0;
        num = abs(num);
        ll res = 0;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        if (negative)
            res = -res;
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        else
            return res;
    }
};