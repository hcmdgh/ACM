#include <cstring>

class Solution {
public:
    char* str;
    int cnt_left;
    int len;
    vector<string> res;

    void dfs(int pos) {
        if (pos >= len) {
            res.emplace_back(string(str));
        } else {
            if (len - pos == cnt_left) {
                memset(str + pos, ')', len - pos);
                dfs(len);
            } else {
                ++cnt_left;
                str[pos] = '(';
                dfs(pos + 1);
                --cnt_left;
                if (cnt_left > 0) {
                    --cnt_left;
                    str[pos] = ')';
                    dfs(pos + 1);
                    ++cnt_left;
                }
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        n <<= 1;
        str = new char[n + 1];
        str[n] = 0;
        cnt_left = 0;
        len = n;
        res.clear();
        dfs(0);
        return res;
    }
};