#include <cassert>
#include <cstring>

typedef pair<int, int> Pair;
vector<Pair> unfilled;
bool row_used[9][10];
bool col_used[9][10];
bool box_used[3][3][10];

bool dfs(int pos, vector<vector<char>>& board) {
    if (pos >= unfilled.size()) {
        return true;
    } else {
        int x = unfilled[pos].first;
        int y = unfilled[pos].second;
        int box_x = x / 3, box_y = y / 3;
        for (int digit = 1; digit <= 9; ++digit) {
            board[x][y] = digit + '0';
            if (!row_used[x][digit] && !col_used[y][digit] && !box_used[box_x][box_y][digit]) {
                row_used[x][digit] = col_used[y][digit] = box_used[box_x][box_y][digit] = true;
                if (dfs(pos + 1, board))
                    return true;
                row_used[x][digit] = col_used[y][digit] = box_used[box_x][box_y][digit] = false;
            }
        }
//        board[x][y] = '.';
        return false;
    }
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unfilled.clear();
        memset(row_used, 0, sizeof(row_used));
        memset(col_used, 0, sizeof(col_used));
        memset(box_used, 0, sizeof(box_used));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    unfilled.emplace_back(i, j);
                } else {
                    int box_x = i / 3;
                    int box_y = j / 3;
                    int digit = board[i][j] - '0';
                    row_used[i][digit] = true;
                    col_used[j][digit] = true;
                    box_used[box_x][box_y][digit] = true;
                }
            }
        }
        bool res = dfs(0, board);
        assert(res);
    }
};