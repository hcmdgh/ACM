#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string KEY = "yizhong";
const int KEY_LENGTH = KEY.length();
const vector<pair<int, int>> DIRECTIONS = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
};

int main() {
    int N;
    cin >> N;
    vector<vector<char>> matrix(N, vector<char>(N));
    vector<vector<bool>> filter(N, vector<bool>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == KEY[0]) {
                for (int k = 0; k < 8; ++k) {
                    int delta_i = DIRECTIONS[k].first;
                    int delta_j = DIRECTIONS[k].second;
                    int ii = i, jj = j;
                    bool valid = true;
                    for (int m = 0; m < KEY_LENGTH - 1; ++m) {
                        ii += delta_i;
                        jj += delta_j;
                        if (ii < 0 || ii >= N ||
                            jj < 0 || jj >= N ||
                            matrix[ii][jj] != KEY[m + 1]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        filter[i][j] = true;
                        ii = i, jj = j;
                        for (int m = 0; m < KEY_LENGTH - 1; ++m) {
                            ii += delta_i;
                            jj += delta_j;
                            filter[ii][jj] = true;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (filter[i][j]) {
                cout << matrix[i][j];
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }

    return 0;
}