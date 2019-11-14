#include <algorithm>

class Solution {
public:
    int N;
    vector<vector<int>> res;
    vector<int> arrangement;

    void dfs(int pos, int remain, const vector<int>& candidates) {
        if (pos >= N) {
            vector<int> _res;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < arrangement[i]; ++j) {
                    _res.emplace_back(candidates[i]);
                }
            }
            res.emplace_back(_res);
        } else {
            int num = candidates[pos];
            if (pos < N - 1) {
                int max_cnt = remain / num;
                for (int i = 0; i <= max_cnt; ++i) {
                    arrangement[pos] = i;
                    dfs(pos + 1, remain - num * i, candidates);
                }
            } else {
                if (remain % num == 0) {
                    arrangement[N - 1] = remain / num;
                    dfs(N, 0, candidates);
                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());
        N = candidates.size();
        arrangement.resize(N);
        dfs(0, target, candidates);
        return res;
    }

    void test() {
        vector<int> candidates = {2, 6, 3, 7};
        auto res = combinationSum(candidates, 7);
        cout << res.size() << endl;
    }
};