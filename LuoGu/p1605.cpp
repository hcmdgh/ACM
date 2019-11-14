#include <iostream>
#include <vector>
using namespace std;

const int EMPTY = 0;
const int BLOCKED = 1;
const int EMPTY_AND_VISITED = 2;
const int BLOCKED_AND_VISITED = 3;

int N, M, T;
vector<vector<int>> layout;
pair<int, int> starting_point, terminal_point;
int count = 0;
const vector<pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};

void explore(int row, int column) {
    if (row < 0 || row >= N || column < 0 || column >= M)
        return;
    if ((layout[row][column] & 2) || layout[row][column] == BLOCKED)
        return;
    if (row == terminal_point.first && column == terminal_point.second) {
        ++count;
        return;
    }
    layout[row][column] ^= 2;
    for (int i = 0; i < 4; ++i) {
        int delta_row = directions[i].first;
        int delta_column = directions[i].second;
        explore(row + delta_row, column + delta_column);
    }
    layout[row][column] ^= 2;
}

int main() {
    cin >> N >> M >> T;
    layout.resize(N, vector<int>(M));
    cin >> starting_point.first >> starting_point.second >>
        terminal_point.first >> terminal_point.second;
    --starting_point.first;
    --starting_point.second;
    --terminal_point.first;
    --terminal_point.second;
    for (int i = 0; i < T; ++i) {
        int row, column;
        cin >> row >> column;
        layout[row - 1][column - 1] = BLOCKED;
    }

    explore(starting_point.first, starting_point.second);
    cout << count << endl;

    return 0;
}