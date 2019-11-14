class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int j = -1;
        for (int i = 0; i < size; ++i) {
            if (j == -1 || nums[i] != nums[j]) {
                ++j;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};