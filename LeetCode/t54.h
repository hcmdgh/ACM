const int DIRECTIONS_X[4] = {0, 1, 0, -1};
const int DIRECTIONS_Y[4] = {1, 0, -1, 0};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return {};
        int col = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int x = 0, y = -1, d = 0;
        while (true) {
            int dx = DIRECTIONS_X[d];
            int dy = DIRECTIONS_Y[d];
            x += dx, y += dy;
            if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) {
                break;
            }
            do {
                printf("x=%d,y=%d\n", x, y);
                printf("dx=%d,dy=%d\n", dx, dy);
                res.emplace_back(matrix[x][y]);
                visited[x][y] = true;
                x += dx, y += dy;
            } while (!(x < 0 || x >= row || y < 0 || y >= col || visited[x][y]));
            x -= dx, y -= dy;
            d = (d + 1) % 4;
        }
        return res;
    }

    void test() {
        vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
        vector<int> res = spiralOrder(m);
        for (int val : res) {
            cout << val << endl;
        }
    }
};