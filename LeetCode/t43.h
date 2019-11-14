class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> a(len1, 0);
        vector<int> b(len2, 0);
        vector<int> c(len1 + len2, 0);
        for (int i = 0; i < len1; ++i) {
            a[i] = num1[len1 - i - 1] - '0';
        }
        for (int i = 0; i < len2; ++i) {
            b[i] = num2[len2 - i - 1] - '0';
        }
        for (int i = 0; i < len2; ++i) {
            int carry = 0;
            for (int j = 0; j < len1; ++j) {
                int temp = c[i + j] + a[j] * b[i] + carry;
                carry = temp / 10;
                c[i + j] = temp % 10;
            }
            c[i + len1] = carry;
        }
        string res;
        int i = len1 + len2 - 1;
        while (i >= 0 && c[i] == 0)
            --i;
        printf("i=%d\n", i);
        while (i >= 0) {
            res.push_back(c[i] + '0');
            --i;
        }
        if (res.length() == 0)
            res = "0";
        for (int i = 0; i < len1 + len2; ++i) {
            printf("%d", c[i]);
        }
        putchar('\n');
        return res;
    }

    void test() {
        string c = multiply("12", "12");
        cout << c << endl;
    }
};