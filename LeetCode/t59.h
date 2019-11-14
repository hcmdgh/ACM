const int DIRECTIONS_X[4] = {0, 1, 0, -1};
const int DIRECTIONS_Y[4] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int x = 0, y = -1, d = 0;
        int num = 0;
        while (true) {
            int dx = DIRECTIONS_X[d];
            int dy = DIRECTIONS_Y[d];
            x += dx, y += dy;
            if (x < 0 || x >= n || y < 0 || y >= n || matrix[x][y]) {
                break;
            }
            do {
                matrix[x][y] = ++num;
                x += dx, y += dy;
            } while (!(x < 0 || x >= n || y < 0 || y >= n || matrix[x][y]));
            x -= dx, y -= dy;
            d = (d + 1) % 4;
        }
        return matrix;
    }
};