#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int N, M;
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};
struct Point {
    bool blocked;
    int last_x, last_y;
} graph[1505][1505];

int readChar() {
    char ch;
    while (true) {
        ch = getchar();
        if (ch == '.')
            return 0;
        if (ch == '#')
            return 1;
        if (ch == 'S')
            return -1;
    }
}

bool dfs(int x, int y) {
    int _x = (x % N + N) % N, _y = (y % M + M) % M;
    Point& p = graph[_x][_y];
    if (p.blocked || (p.last_x == x && p.last_y == y)) {
        return false;
    } else if (p.last_x < INT_MAX && p.last_y < INT_MAX) {
        return true;
    } else {
        p.last_x = x, p.last_y = y;
        bool res = false;
        for (int d = 0; d < 4; ++d) {
            res = res || dfs(x + DIRECTIONS_X[d], y + DIRECTIONS_Y[d]);
        }
        return res;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    while (scanf("%d%d", &N, &M) == 2) {
        int srcX, srcY;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int temp = readChar();
                graph[i][j].blocked = temp > 0;
                graph[i][j].last_x = graph[i][j].last_y = INT_MAX;
                if (temp == -1)
                    srcX = i, srcY = j;
            }
        }
        if (dfs(srcX, srcY)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
