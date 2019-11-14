#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

int N;
enum {FRONT, LEFT, BACK, RIGHT, UP, DOWN};
char views[6][10][10];
char cubes[10][10][10];

char read_char() {
    char ch;
    do {
        ch = getchar();
    } while (ch != '.' && (ch < 'A' || ch > 'Z'));
    return ch;
}

void get_pos(int view, int x, int y, int depth, int& _x, int& _y, int& _z) {
    if (view == FRONT) {
        _x = N - 1 - depth;
        _y = y;
        _z = N - 1 - x;
    } else if (view == BACK) {
        _x = depth;
        _y = N - 1 - y;
        _z = N - 1 - x;
    } else if (view == LEFT) {
        _x = y;
        _y = depth;
        _z = N - 1 - x;
    } else if (view == RIGHT) {
        _x = N - 1 - y;
        _y = N - 1 - depth;
        _z = N - 1 - x;
    } else if (view == UP) {
        _x = x;
        _y = y;
        _z = N - 1 - depth;
    } else if (view == DOWN) {
        _x = N - 1 - x;
        _y = y;
        _z = depth;
    } else {
        assert(0);
    }
}

int main() {
//    ios::sync_with_stdio(false);
    while ((cin >> N) && N > 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < N; ++k) {
                    views[j][i][k] = read_char();
                }
            }
        }

        memset(cubes, '#', sizeof(cubes));
        for (int view = 0; view < 6; ++view) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (views[view][i][j] == '.') {
                        for (int depth = 0; depth < N; ++depth) {
                            int x, y, z;
                            get_pos(view, i, j, depth, x, y, z);
                            cubes[x][y][z] = '.';
                        }
                    }
                }
            }
        }

        bool done = false;
        while (!done) {
            done = true;
            for (int view = 0; view < 6; ++view) {
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        for (int depth = 0; depth < N; ++depth) {
                            int x, y, z;
                            get_pos(view, i, j, depth, x, y, z);
                            char& color = cubes[x][y][z];
                            char view_color = views[view][i][j];
                            if (view_color == '.')
                                break;
                            if (color != '.') {
                                if (color == '#') {
                                    color = view_color;
                                    break;
                                } else if (color != view_color) {
                                    color = '.';
                                    done = false;
                                } else /*if (color == view_color)*/ {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    if (cubes[i][j][k] != '.')
                        ++cnt;
                }
            }
        }

        cout << "Maximum weight: " << cnt << " gram(s)" << endl;
    }

    return 0;
}
