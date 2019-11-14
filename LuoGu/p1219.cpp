#include <iostream>
#include <vector>
using namespace std;

int N;
int count = 0;
vector<int> layout;
vector<bool> column_flag;
// 对角线：从左上到右下
vector<bool> diagonal1_flag;
// 对角线：从左下到右上
vector<bool> diagonal2_flag;

void explore(int row) {
    if (row >= N) {
        ++count;
        if (count <= 3) {
            for (int i = 0; i < N; ++i) {
                cout << layout[i] + 1 << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < N; ++i) {
            if (!column_flag[i] && !diagonal2_flag[i + row]
                && !diagonal1_flag[N - 1 - i + row]) {
                column_flag[i] = true;
                diagonal2_flag[i + row] = true;
                diagonal1_flag[N - 1 - i + row] = true;

                layout[row] = i;
                explore(row + 1);

                column_flag[i] = false;
                diagonal2_flag[i + row] = false;
                diagonal1_flag[N - 1 - i + row] = false;
            }
        }
    }
}

int main() {
    cin >> N;
    layout.resize(N);
    column_flag.resize(N);
    diagonal1_flag.resize(2 * N - 1);
    diagonal2_flag.resize(2 * N - 1);

    explore(0);

    cout << count << endl;

    return 0;
}