#include <string>

class Solution {
public:
    int extend(const string& s, int L, int R) {
        int length = s.length();
        int ans = 0;
        while (L >= 0 && R < length && s[L] == s[R]) {
            ++ans, --L, ++R;
        }
        return ans;
    }

    string longestPalindrome(string s) {
        int length = s.length();
        string ans;
        int max_len = 0;
        for (int i = 0; i < length; ++i) {
            int temp = extend(s, i, i);
            int len = (temp << 1) - 1;
            if (len > max_len) {
                ans = s.substr(i - temp + 1, len);
                max_len = len;
            }
        }
        for (int i = 0; i < length - 1; ++i) {
            int temp = extend(s, i, i + 1);
            int len = temp << 1;
            if (len > max_len) {
                ans = s.substr(i - temp + 1, len);
                max_len = len;
            }
        }
        return ans;
    }
};