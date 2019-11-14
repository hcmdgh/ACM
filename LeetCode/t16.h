#include <algorithm>
#include <climits>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size <= 2)
            return 0;
        int min_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int L = i + 1, R = size - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                int diff = sum - target;
                if (abs(diff) < abs(min_diff)) {
                    min_diff = diff;
                    if (min_diff == 0)
                        return target;
                }
                if (sum > target) {
                    --R;
                } else if (sum < target) {
                    ++L;
                }
            }
        }
        return target + min_diff;
    }
};