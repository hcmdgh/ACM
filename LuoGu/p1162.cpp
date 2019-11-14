#include <iostream>
#include <vector>
using namespace std;

int N;
const vector<pair<int, int>> DIRECTIONS = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};
const int EMPTY = 0;
const int WALL = 1;
const int VISITED = -1;

void dfs(vector<vector<int>>& layout, int x, int y) {
    if (x < 0 || x >= N + 2 || y < 0 || y >= N + 2)
        return;
    if (layout[x][y] == WALL || layout[x][y] == VISITED)
        return;
    layout[x][y] = VISITED;
    for (int i = 0; i < 4; ++i) {
        dfs(layout, x + DIRECTIONS[i].first, y + DIRECTIONS[i].second);
    }
}

int main() {
    cin >> N;
    vector<vector<int>> layout(N + 2, vector<int>(N + 2));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> layout[i][j];
        }
    }

    dfs(layout, 0, 0);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            switch (layout[i][j]) {
                case VISITED:
                    cout << "0 ";
                    break;
                case WALL:
                    cout << "1 ";
                    break;
                default:
                    cout << "2 ";
            }
        }
        cout << endl;
    }

    return 0;
}