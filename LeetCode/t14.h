class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0)
            return "";
        int len = 0;
        string res;
        while (true) {
            int common_ch = -1;
            for (int i = 0; i < size; ++i) {
                const string& str = strs[i];
                if (len >= str.length())
                    return res;
                char ch = str[len];
                if (common_ch == -1)
                    common_ch = ch;
                else if (common_ch != ch)
                    return res;
            }
            res.push_back(strs[0][len]);
            ++len;
        }
    }
};