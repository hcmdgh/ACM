#include <cstring>
#define CLEAR memset(used, 0, sizeof(used))
#define READ(x, y) (board[x][y] == '.' ? 0 : board[x][y] - '0')

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[10];
        for (int row = 0; row < 9; ++row) {
            CLEAR;
            for (int col = 0; col < 9; ++col) {
                int digit = READ(row, col);
                if (digit) {
                    if (used[digit])
                        return false;
                    used[digit] = true;
                }
            }
        }
        for (int col = 0; col < 9; ++col) {
            CLEAR;
            for (int row = 0; row < 9; ++row) {
                int digit = READ(row, col);
                if (digit) {
                    if (used[digit])
                        return false;
                    used[digit] = true;
                }
            }
        }
        for (int ii = 0; ii < 3; ++ii) {
            for (int jj = 0; jj < 3; ++jj) {
                CLEAR;
                for (int i = ii * 3; i < (ii+1) * 3; ++i) {
                    for (int j = jj * 3; j < (jj+1) * 3; ++j) {
                        int digit = READ(i, j);
                        if (digit) {
                            if (used[digit])
                                return false;
                            used[digit] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};