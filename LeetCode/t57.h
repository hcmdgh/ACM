#include <algorithm>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        if (size == 0)
            return {newInterval};
        vector<int> Ls(size);
        vector<int> Rs(size);
        for (int i = 0; i < size; ++i) {
            Ls[i] = intervals[i][0];
            Rs[i] = intervals[i][1];
        }
        int L = newInterval[0];
        int R = newInterval[1];
        int begin = 0, end = size - 1;
        int pos = -1;
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (Rs[mid] < L) {
                begin = mid + 1;
            } else if (R < Ls[mid]) {
                end = mid - 1;
            } else {
                pos = mid;
                break;
            }
        }
    }
};