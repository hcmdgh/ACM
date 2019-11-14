#include <map>

class Solution {
public:
    map<int, int, greater<int>> num2cnt;
    vector<vector<int>> res;
    int N;
    vector<int> nums, max_counts;
    vector<int> counts;

    void dfs(int pos, int remain) {
        if (pos >= N) {
            vector<int> _res;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < counts[i]; ++j) {
                    _res.emplace_back(nums[i]);
                }
            }
            res.emplace_back(_res);
        } else {
            int num = nums[pos];
            if (pos == N - 1) {
                if (remain % num == 0) {
                    counts[pos] = remain / num;
                    if (counts[pos] <= max_counts[pos])
                        dfs(pos + 1, 0);
                }
            } else {
                int max_cnt = min(max_counts[pos], remain / num);
                printf("num=%d max_cnt=%d\n", num, max_cnt);
                for (int i = 0; i <= max_cnt; ++i) {
                    counts[pos] = i;
                    dfs(pos + 1, remain - num * i);
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (int num : candidates) {
            ++num2cnt[num];
        }
        N = num2cnt.size();
        printf("N=%d\n", N);
        nums.resize(N);
        max_counts.resize(N);
        counts.resize(N);
        auto iter = num2cnt.begin();
        for (int i = 0; i < N; ++i) {
            nums[i] = iter->first;
            max_counts[i] = iter->second;
            ++iter;
        }
        dfs(0, target);
        return res;
    }

    void test() {
        vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
        auto res = combinationSum2(nums, 8);
        printf("%d\n", res.size());
    }
};