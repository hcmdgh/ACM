class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> arr(n, vector<int>(m, 0));
        int size = indices.size();
        for (int i = 0; i < size; ++i) {
            int x = indices[i][0];
            int y = indices[i][1];
            for (int _i = 0; _i < n; ++_i) {
                ++arr[_i][y];
            }
            for (int j = 0; j < m; ++j) {
                ++arr[x][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt += arr[i][j] & 1;
            }
        }
        return cnt;
    }
};