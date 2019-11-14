class Solution {
public:
    int strStr(string haystack, string needle) {
        int llen = haystack.length();
        int slen = needle.length();
        for (int i = 0; i + slen - 1 < llen; ++i) {
            bool valid = true;
            for (int j = 0; j < slen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return i;
            }
        }
        return -1;
    }
};