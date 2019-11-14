#include <string>
#include <cstring>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        int pos[130];
        memset(pos, -1, sizeof(pos));
        int begin_pos = 0;
        int ans = 0;
        for (int i = 0; i < length; ++i) {
            char ch = s[i];
            if (pos[ch] > -1 && pos[ch] >= begin_pos) {
                begin_pos = pos[ch] + 1;
            }
            pos[ch] = i;
            ans = max(ans, i - begin_pos + 1);
        }
        return ans;
    }

    void test() {
        printf("%d\n", lengthOfLongestSubstring("abba"));
    }
};