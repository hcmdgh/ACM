#include <string>

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.length();
        if (numRows == 1)
            return s;
        string res;
        for (int i = 0; i < numRows; ++i) {
            int add = numRows * 2 - i * 2 - 2;
            if (!add)
                add = numRows * 2 - 2;
            for (int j = i; j < length;) {
                res.push_back(s[j]);
                j += add;
                if (i > 0 && i < numRows - 1)
                    add = numRows * 2 - 2 - add;
            }
        }
        return res;
    }
};