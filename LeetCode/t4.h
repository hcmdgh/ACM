#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        vector<int> res(size);
        int cur1 = 0, cur2 = 0;
        for (int i = 0; i < size; ++i) {
            if (cur2 >= size2 || (cur1 < size1 && nums1[cur1] < nums2[cur2])) {
                res[i] = nums1[cur1];
                ++cur1;
            } else {
                res[i] = nums2[cur2];
                ++cur2;
            }
        }
        if (size & 1) {
            return res[size >> 1];
        } else {
            return (res[size >> 1] + res[(size >> 1) - 1]) * 0.5;
        }
    }

    void test() {
        vector<int> a1 = {1, 2};
        vector<int> a2 = {3, 4};
        double res = findMedianSortedArrays(a1, a2);
        cout << res << endl;
    }
};