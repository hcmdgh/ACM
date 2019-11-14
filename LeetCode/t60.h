#include <algorithm>

class Solution {
public:
    string getPermutation(int n, int k) {
        string perm;
        for (int i = 0; i < n; ++i) {
            perm.push_back(i + '1');
        }
        for (int i = 0; i < k - 1; ++i) {
            next_permutation(perm.begin(), perm.end());
        }
        return perm;
    }
};