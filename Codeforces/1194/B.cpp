#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const bool WHITE = false;
const bool BLACK = true;
bool layout[400000];
int white_row[50000];
int white_column[50000];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    char input;
    for (int query = 0; query < Q; ++query) {
        int N, M;
        cin >> N >> M;

        memset(white_row, 0, sizeof(int) * N);
        memset(white_column, 0, sizeof(int) * M);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> input;
                if (input == '.') {
                    layout[i * M + j] = WHITE;
                    ++white_row[i];
                    ++white_column[j];
                } else {
                    layout[i * M + j] = BLACK;
                }
            }
        }

        int min_paint = INT_MAX;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int paint;
                if (layout[i * M + j] == BLACK) {
                    paint = white_row[i] + white_column[j];
                } else {
                    paint = white_row[i] + white_column[j] - 1;
                }
                if (paint < min_paint) {
                    min_paint = paint;
                }
            }
        }

        cout << min_paint << endl;
    }

    return 0;
}