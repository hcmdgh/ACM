#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int ans = 0;
        int L = 0, R = size - 1;
        while (L < R) {
            ans = max(ans, (R-L)*min(height[L], height[R]));
            if (height[L] < height[R]) {
                ++L;
            } else {
                --R;
            }
        }
        return ans;
    }
};