#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char graph[1505][1505];
int visited[1505][1505][3];
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};

char readChar() {
    char ch;
    do {
        ch = getchar();
    } while (ch != '#' && ch != '.' && ch != 'S');
    return ch;
}

bool dfs(int x, int y) {
    int pro_x = (x % N + N) % N;
    int pro_y = (y % M + M) % M;
    if (graph[pro_x][pro_y] == '#') {
        return false;
    } else if (visited[pro_x][pro_y][0] && visited[pro_x][pro_y][1] == x && visited[pro_x][pro_y][2] == y) {
        return false;
    } else if (visited[pro_x][pro_y][0]) {
        return true;
    }
    visited[pro_x][pro_y][0] = true;
    visited[pro_x][pro_y][1] = x;
    visited[pro_x][pro_y][2] = y;
    for (int d = 0; d < 4; ++d) {
        int next_x = x + DIRECTIONS_X[d];
        int next_y = y + DIRECTIONS_Y[d];
        if (dfs(next_x, next_y))
            return true;
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        int src_x = -1, src_y = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                char ch = readChar();
                graph[i][j] = ch;
                if (ch == 'S')
                    src_x = i, src_y = j;
            }
        }
        memset(visited, 0, sizeof(visited));
        if (dfs(src_x, src_y)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}