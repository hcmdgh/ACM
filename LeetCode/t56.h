#include <algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int begin = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] > end) {
                res.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({begin, end});
        return res;
    }
};