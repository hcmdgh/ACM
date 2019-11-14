
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> _nums(size << 1);
        for (int i = 0; i < size; ++i) {
            _nums[i] = _nums[i + size] = nums[i];
        }
        int pivot = -1;
        for (int i = 0; i < size; ++i) {
            if (_nums[i] > _nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        int begin = pivot + 1, end = pivot + size;
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (target > _nums[mid]) {
                begin = mid + 1;
            } else if (target < _nums[mid]) {
                end = mid - 1;
            } else {
                return mid % size;
            }
        }
        return -1;
    }
};