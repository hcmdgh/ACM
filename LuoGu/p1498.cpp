#include <iostream>
using namespace std;

const int MAX_ROW = 2048;
const int MAX_COLUMN = 4096;
char layout[MAX_ROW][MAX_COLUMN];

const char atom[2][5] = {
    " /\\ ",
    "/__\\",
};

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int row = 2, column = 4;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            layout[MAX_ROW - row + i][j] = atom[i][j];
        }
    }

    for (int k = 2; k <= N; ++k) {
        for (int i = MAX_ROW - row; i < MAX_ROW; ++i) {
            for (int j = 0; j < column; ++j) {
                layout[i][j + column] = layout[i][j];
                layout[i - row][j + column / 2] = layout[i][j];
            }
        }
        row *= 2;
        column *= 2;
    }

    for (int i = MAX_ROW - row; i < MAX_ROW; ++i) {
        for (int j = 0; j < column; ++j) {
            if (layout[i][j] == 0)
                cout << ' ';
            else
                cout << layout[i][j];
        }
        cout << endl;
    }
}