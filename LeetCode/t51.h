class Solution {
public:
    vector<int> layout;
    int N;
    vector<vector<string>> res;

    void dfs(int row) {
        if (row >= N) {
            vector<string> _res(N, string(N, '.'));
            for (int i = 0; i < N; ++i) {
                _res[i][layout[i]] = 'Q';
            }
            res.emplace_back(_res);
        } else {
            for (int col = 0; col < N; ++col) {
                int x = row - 1, y = col;
                while (x >= 0 && layout[x] != y)
                    --x;
                if (x < 0) {
                    x = row - 1, y = col - 1;
                    while (x >= 0 && y >= 0 && layout[x] != y)
                        --x, --y;
                    if (x < 0 || y < 0) {
                        x = row - 1, y = col + 1;
                        while (x >= 0 && y < N && layout[x] != y) {
                            --x, ++y;
                        }
                        if (x < 0 || y >= N) {
                            layout[row] = col;
                            dfs(row + 1);
                        }
                    }
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        layout.resize(n);
        dfs(0);
        return res;
    }
};