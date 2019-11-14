const int DIRECTIONS_X[4] = {1, -1, 0, 0};
const int DIRECTIONS_Y[4] = {0, 0, 1, -1};

class Solution {
public:
    int N, M;
    bool valid;

    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= N || y < 0 || y >= M) {
            valid = false;
        } else if (grid[x][y] == 0) {
            grid[x][y] = -1;
            for (int d = 0; d < 4; ++d) {
                int next_x = x + DIRECTIONS_X[d];
                int next_y = y + DIRECTIONS_Y[d];
                dfs(next_x, next_y, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 0) {
                    valid = true;
                    dfs(i, j, grid);
                    cnt += valid;
                }
            }
        }
        return cnt;
    }

    void test() {
        vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},
                                    {1,0,0,0,0,1,1,0},
                                    {1,0,1,0,1,1,1,0},
                                    {1,0,0,0,0,1,0,1},
                                    {1,1,1,1,1,1,1,0}};
        cout << closedIsland(grid) << endl;
    }
};