#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N;
bool layout[30][30];
const int DIRECTIONS_X[4] = {-1, 0, 1, 0};
const int DIRECTIONS_Y[4] = {0, 1, 0, -1};
struct State {
    int x, y, face, color, time;

    State(int x, int y, int face, int color, int time) :
        x(x), y(y), face(face), color(color), time(time) {}
};
bool visited[30][30][4][5];

int readChar() {
    while (true) {
        char ch = getchar();
        if (ch == '#')
            return 0;
        if (ch == '.')
            return 1;
        if (ch == 'S')
            return 2;
        if (ch == 'T')
            return 3;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int kase = 0;
    while (scanf("%d%d", &N, &M) == 2 && N > 0 && M > 0) {
        if (kase)
            putchar('\n');
        int src_x = -1, src_y = -1, dest_x = -1, dest_y = -1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                int state = readChar();
                if (state <= 1) {
                    layout[i][j] = state;
                } else if (state == 2) {
                    layout[i][j] = true;
                    src_x = i, src_y = j;
                } else {
                    layout[i][j] = true;
                    dest_x = i, dest_y = j;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        queue<State> states;
        states.emplace(State(src_x, src_y, 0, 0, 0));
        visited[src_x][src_y][0][0] = true;
        int ans = -1;
        while (!states.empty()) {
            State top = states.front();
            states.pop();
            int x = top.x, y = top.y, face = top.face, color = top.color, _time = top.time;
            if (x == dest_x && y == dest_y && color == 0) {
                ans = _time;
                break;
            }
            if (!visited[x][y][(face+1)%4][color]) {
                visited[x][y][(face+1)%4][color] = true;
                states.emplace(State(x, y, (face+1)%4, color, _time + 1));
            }
            if (!visited[x][y][(face-1+4)%4][color]) {
                visited[x][y][(face-1+4)%4][color] = true;
                states.emplace(State(x, y, (face-1+4)%4, color, _time + 1));
            }
            int next_x = x + DIRECTIONS_X[face];
            int next_y = y + DIRECTIONS_Y[face];
            if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M && layout[next_x][next_y]) {
                if (!visited[next_x][next_y][face][(color+1)%5]) {
                    visited[next_x][next_y][face][(color+1)%5] = true;
                    states.emplace(State(next_x, next_y, face, (color+1)%5, _time + 1));
                }
            }
        }
        printf("Case #%d\n", ++kase);
        if (ans == -1) {
            printf("destination not reachable\n");
        } else {
            printf("minimum time = %d sec\n", ans);
        }
    }

    return 0;
}
