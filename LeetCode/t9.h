class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        char digits[15];
        int cnt = 0;
        while (x > 0) {
            digits[cnt++] = x % 10;
            x /= 10;
        }
        for (int i = 0, j = cnt - 1; i < j; ++i, --j) {
            if (digits[i] != digits[j]) {
                return false;
            }
        }
        return true;
    }
};