#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_subsequence(const string& s, const string& t) {
    int len_s = s.length();
    int len_t = t.length();
    int cur = 0;
    for (int i = 0; i < len_s; ++i) {
        if (s[i] == t[cur]) {
            ++cur;
            if (cur >= len_t)
                break;
        }
    }
    return cur >= len_t;
}

int main() {
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;

    int lenS = S.length();
    int lenT = T.length();
    int max_length = 0;
    for (int i = 0; i < lenS; ++i) {
        for (int j = 1; j <= lenS - i; ++j) {
            string _s = S.substr(0, i) + S.substr(i + j);
            if (is_subsequence(_s, T)) {
                max_length = max(max_length, j);
            }
        }
    }

    cout << max_length << endl;

    return 0;
}
