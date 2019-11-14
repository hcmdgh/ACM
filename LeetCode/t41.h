class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        vector<bool> used(size + 1, false);
        for (int num : nums) {
            if (num > 0 && num <= size) {
                used[num] = true;
            }
        }
        for (int i = 1; i <= size; ++i) {
            if (!used[i]) {
                return i;
            }
        }
        return size + 1;
    }
};