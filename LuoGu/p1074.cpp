#include <iostream>
#include <algorithm>
using namespace std;

int layout[9][9];
int emptyPoints[81];
int emptyPointsCount = 0;
int max_score = -1;
bool usedInRow[9][9];
bool usedInColumn[9][9];
bool usedInBlock[9][9];

// 读入数独中已有数据
void loadData() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int val = layout[i][j] - 1;
            if (val >= 0) {
                int _x, _y, _index;
                _x = i / 3 * 3;
                _y = j / 3 * 3;
                _index = _x + _y / 3;
                usedInRow[i][val] = usedInColumn[j][val] = usedInBlock[_index][val] = true;
            }
        }
    }
}

// 安排填空格的顺序
void arrangeOrder() {
    pair<int, int> rows[9];  // 存储每一行的空格数，然后排序
    for (int i = 0; i < 9; ++i) {
        rows[i].first = i;
        int& count = rows[i].second;
        count = 0;
        for (int j = 0; j < 9; ++j) {
            if (layout[i][j] == 0)
                ++count;
        }
    }
    auto func = [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    };
    sort(rows, rows + 9, func);
    emptyPointsCount = 0;
    for (int i = 0; i < 9; ++i) {
        int row = rows[i].first;
        for (int j = 0; j < 9; ++j) {
            if (layout[row][j] == 0) {
                emptyPoints[emptyPointsCount] = row * 9 + j;
                ++emptyPointsCount;
            }
        }
    }
}

// 计算总得分
int calcScore() {
    int score = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int power;
            if (i == 0 || i == 8 || j == 0 || j == 8)
                power = 6;
            else if (i == 1 || i == 7 || j == 1 || j == 7)
                power = 7;
            else if (i == 2 || i == 6 || j == 2 || j == 6)
                power = 8;
            else if (i == 3 || i == 5 || j == 3 || j == 5)
                power = 9;
            else
                power = 10;
            score += power * layout[i][j];
        }
    }
    return score;
}

void dfs(int index) {
    if (index >= emptyPointsCount) {
        int score = calcScore();
        if (score > max_score) {
            max_score = score;
        }
    } else {
        int x = emptyPoints[index] / 9;
        int y = emptyPoints[index] % 9;
        int _x, _y, _index;
        _x = x / 3 * 3;
        _y = y / 3 * 3;
        _index = _x + _y / 3;
        for (int val = 0; val < 9; ++val) {
            if (!usedInRow[x][val] && !usedInColumn[y][val] && !usedInBlock[_index][val]) {
                usedInRow[x][val] = usedInColumn[y][val] = usedInBlock[_index][val] = true;
                layout[x][y] = val + 1;
                dfs(index + 1);
                usedInRow[x][val] = usedInColumn[y][val] = usedInBlock[_index][val] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> layout[i][j];
        }
    }

    loadData();
    arrangeOrder();

    dfs(0);

    cout << max_score << endl;

    return 0;
}