#include <vector>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> num2idx;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            num2idx[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i) {
            int remain = target - nums[i];
            auto iter = num2idx.find(remain);
            if (iter != num2idx.end() && iter->second != i) {
                return {i, iter->second};
            }
        }
        return {};
    }
};