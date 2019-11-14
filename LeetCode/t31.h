class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if (i >= 0) {
            int j = size - 1;
            while (j >= 0 && nums[j] <= nums[i])
                --j;
            swap(nums[i], nums[j]);
        }
        // reverse nums[i+1:]
        for (int L = i + 1, R = size - 1; L < R; ++L, --R) {
            swap(nums[L], nums[R]);
        }
    }
};