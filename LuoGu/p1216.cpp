#include <iostream>
using namespace std;

int layout[1000][1000];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> layout[i][j];
        }
    }

    for (int i = 1; i < N; ++i) {
        layout[i][0] += layout[i-1][0];
        for (int j = 1; j < i; ++j) {
            layout[i][j] += max(layout[i-1][j-1], layout[i-1][j]);
        }
        layout[i][i] += layout[i-1][i-1];
    }

    int result = layout[N - 1][0];
    for (int i = 1; i < N; ++i) {
        result = max(result, layout[N - 1][i]);
    }
    cout << result << endl;

    return 0;
}