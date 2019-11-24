typedef long long ll;

ll C(int m, int n) {
    ll res = 1;
    if (m - n < n) {
        n = m - n;
    }
    for (int i = 0; i < n; ++i) {
        res = res * (m - i) / (i + 1);
    }
    return res;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        return C(m + n - 2, m - 1);
    }
};