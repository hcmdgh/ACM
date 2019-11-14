typedef long long ll;

class Solution {
public:
    double myPow(double x, ll n) {
        bool negative = false;
        if (n < 0) {
            negative = true;
            n = -n;
        }
        double res = 1;
        while (n > 0) {
            if (n & 1) {
                if (negative)
                    res /= x;
                else
                    res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};