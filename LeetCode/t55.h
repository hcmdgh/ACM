class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int range = 0;
        for (int i = 0; i <= range; ++i) {
            range = max(range, i + nums[i]);
            if (range >= size - 1) {
                return true;
            }
        }
        return false;
    }
};