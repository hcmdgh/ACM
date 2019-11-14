#include <cctype>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int begin_cur = s.length() - 1;
        while (begin_cur >= 0 && s[begin_cur] == ' ')
            --begin_cur;
        int cur = begin_cur;
        while (cur >= 0 && isalpha(s[cur])) {
            --cur;
        }
        return begin_cur - cur;
    }

    void test() {
        cout << lengthOfLastWord("fd afd  ") << endl;
    }
};