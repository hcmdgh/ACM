class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int begin = 0, end = size - 1;
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};