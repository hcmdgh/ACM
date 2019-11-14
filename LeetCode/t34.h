class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();

        // 找到大于等于target的第一个元素
        int begin = 0, end = size - 1;
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        int pos_begin = begin;
        if (pos_begin >= size || nums[pos_begin] != target) {
            return {-1, -1};
        }

        // 找到小于等于target的最后一个元素
        begin = 0, end = size - 1;
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (nums[mid] <= target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        int pos_end = end;
        if (pos_end < 0 || nums[pos_end] != target) {
            return {-1, -1};
        }
        return {pos_begin, pos_end};
    }
};