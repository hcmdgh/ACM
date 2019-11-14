class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        int cur1 = 0;
        int sum = 0;
        while (cur1 < N) {
            int h1 = height[cur1];
            if (h1 > 0) {
                int cur2 = cur1 + 1;
                while (cur2 < N && height[cur2] < cur1)
                    ++cur2;
                if (cur2 < N) {
                    for (int i = cur1 + 1; i < cur2; ++i) {
                        sum += h1 - height[i];
                    }
                    cur1 = cur2 - 1;
                }
            }
            ++cur1;
        }
        return sum;
    }
};