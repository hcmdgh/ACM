#include <algorithm>
#include <set>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 2 && nums[i] <= 0; ++i) {
            int num1 = nums[i];
            int L = i + 1, R = size - 1;
            while (L < R) {
                int num2 = nums[L];
                int num3 = nums[R];
                int sum = num1 + num2 + num3;
                if (sum == 0) {
                    res.emplace_back(num1, num2, num3);
                    while (L < size && nums[L] == num2)
                        ++L;
                    while (R >= 0 && nums[R] == num3)
                        --R;
                } else if (sum > 0) {
                    --R;
                } else {
                    ++L;
                }
            }
        }
        return res;
    }
};