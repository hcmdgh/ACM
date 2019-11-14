class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i) {
            string temp;
            char last_ch = 0;
            int cnt = 0;
            for (char ch : res) {
                if (last_ch && ch != last_ch) {
                    temp += to_string(cnt);
                    temp += last_ch;
                    cnt = 0;
                }
                ++cnt;
                last_ch = ch;
            }
            temp += to_string(cnt);
            temp += last_ch;
            res = temp;
        }
        return res;
    }

    void test() {
        cout << countAndSay(3) << endl;
    }
};