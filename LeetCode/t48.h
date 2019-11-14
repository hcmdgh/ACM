class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int L = 0, R = size - 1; L < R; ++L, --R) {
                swap(matrix[i][L], matrix[i][R]);
            }
        }
    }
};