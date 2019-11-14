#include <iostream>
using namespace std;

int R, C;
int layout[100][100];
int max_length[100][100];
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};

inline void add_max(int& max_value, int value) {
    if (value > max_value) {
        max_value = value;
    }
}

void dfs(int x, int y) {
    if (max_length[x][y] == 1) {
        int _layout = layout[x][y];
        int _max_length = 1;
        for (int i = 0; i < 4; ++i) {
            int next_x = x + DIRECTIONS_X[i];
            int next_y = y + DIRECTIONS_Y[i];
            if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C
                && layout[next_x][next_y] < _layout) {
                dfs(next_x, next_y);
                add_max(_max_length, max_length[next_x][next_y] + 1);
            }
        }
        max_length[x][y] = _max_length;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> layout[i][j];
            max_length[i][j] = 1;
        }
    }

    int result = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            dfs(i, j);
            add_max(result, max_length[i][j]);
        }
    }

    cout << result << endl;

    return 0;
}