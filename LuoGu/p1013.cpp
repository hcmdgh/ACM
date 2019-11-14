#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string table[9][9];
map<char, int> alpha2num;
int _map[9];
int N;

void error() {
    cout << "ERROR!" << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> table[i][j];
        }
    }

    for (int i = 1; i < N; ++i) {
        alpha2num[table[0][i][0]] = -1;
    }
    bool valid = false;
    for (int i = 1; i < N && !valid; ++i) {
        for (int j = 1; j < N && !valid; ++j) {
            if (table[i][j].length() > 1) {
                alpha2num[table[i][j][0]] = 1;
                valid = true;
            }
        }
    }
    if (!valid) error();
    valid = false;
    for (int i = 1; i < N; ++i) {
        bool all_same = true;
        for (int j = 1; j < N; ++j) {
            if (table[i][j] != table[0][j]) {
                all_same = false;
                break;
            }
        }
        if (all_same) {
            int &temp = alpha2num[table[i][0][0]];
            if (temp == -1) {
                temp = 0;
                valid = true;
                break;
            } else {
                error();
            }
        }
    }
    if (!valid) error();

    for (int i = 0; i < N - 3; ++i) {
        _map[i] = i + 2;
    }
    do {
        int cur = 0;
        for (auto &entry : alpha2num) {
            if (entry.second != 0 && entry.second != 1) {
                entry.second = _map[cur++];
            }
        }
        bool valid = true;
        for (int i = 1; i < N && valid; ++i) {
            for (int j = 1; j < N && valid; ++j) {
                int sum = alpha2num[table[i][0][0]] + alpha2num[table[0][j][0]];
                int digit1 = sum / (N - 1);
                int digit0 = sum % (N - 1);
                string &real_sum = table[i][j];
                if (digit1 > 0) {
                    if (real_sum.length() < 2 ||
                        alpha2num[real_sum[0]] != digit1 ||
                        alpha2num[real_sum[1]] != digit0) {
                        valid = false;
                    }
                } else if (alpha2num[real_sum[0]] != digit0) {
                    valid = false;
                }
            }
        }
        if (valid) {
            for (int i = 1; i < N; ++i) {
                cout << table[0][i][0] << '=' << alpha2num[table[0][i][0]] << ' ';
            }
            cout << endl << N - 1 << endl;
            return 0;
        }
    } while (next_permutation(_map, _map + N - 3));
    error();

    return 0;
}