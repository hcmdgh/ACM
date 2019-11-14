#include <cstring>
const char MAP[10][5] = {"", "", "abc", "def",
                      "ghi", "jkl", "mno",
                      "pqrs", "tuv", "wxyz"};
string str;
int str_len;
string chs;
vector<string> res;

void dfs(int pos) {
    if (pos >= str_len) {
        res.emplace_back(chs);
    } else {
        int digit = str[pos] - '0';
        const char* ch = MAP[digit];
        while (*ch) {
            chs[pos] = *ch;
            dfs(pos + 1);
            ++ch;
        }
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        str = digits;
        str_len = digits.length();
        if (str_len == 0)
            return {};
        chs.resize(str_len);
        res.clear();
        dfs(0);
        return res;
    }
};