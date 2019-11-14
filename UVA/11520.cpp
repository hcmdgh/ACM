#include <iostream>
using namespace std;

int N;
char layout[15][15];
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int Q;
    scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%s", layout[i]);
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char& ch = layout[i][j];
                if (ch == '.') {
                    ch = 'A' - 1;
                    bool valid;
                    do {
                        ++ch;
                        valid = true;
                        for (int d = 0; d < 4; ++d) {
                            int x = i + DIRECTIONS_X[d];
                            int y = j + DIRECTIONS_Y[d];
                            if (x >= 0 && x < N && y >= 0 && y < N && ch == layout[x][y]) {
                                valid = false;
                                break;
                            }
                        }
                    } while (!valid);
                }
            }
        }

        printf("Case %d:\n", q + 1);
        for (int i = 0; i < N; ++i) {
            printf("%s\n", layout[i]);
        }
    }

    return 0;
}
