#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int Q, R, C;
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};
char layout[1005][1005];
int fire_time[1005][1005];
bool visited[1005][1005];
struct State {
    int x, y, time;

    State(int x, int y, int time = 0) : x(x), y(y), time(time) {}
};

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &R, &C);
        queue<State> states;
        int src_x = -1, src_y = -1;
        for (int i = 1; i <= R; ++i) {
            scanf("%s", layout[i] + 1);
            for (int j = 1; j <= C; ++j) {
                visited[i][j] = false;
                fire_time[i][j] = INT_MAX;
                char ch = layout[i][j];
                if (ch == 'J') {
                    ch = '.';
                    src_x = i, src_y = j;
                } else if (ch == 'F') {
                    ch = '.';
                    states.emplace(State(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        while (!states.empty()) {
            State top = states.front();
            states.pop();
            int x = top.x, y = top.y, time = top.time;
            fire_time[x][y] = time;
            for (int d = 0; d < 4; ++d) {
                int next_x = x + DIRECTIONS_X[d];
                int next_y = y + DIRECTIONS_Y[d];
                if (next_x >= 1 && next_y >= 1 && next_x <= R && next_y <= C) {
                    if (layout[next_x][next_y] != '#' && !visited[next_x][next_y]) {
                        visited[next_x][next_y] = true;
                        states.emplace(State(next_x, next_y, time + 1));
                    }
                }
            }
        }
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                visited[i][j] = false;
            }
        }
        states.emplace(State(src_x, src_y, 0));
        visited[src_x][src_y] = true;
        int fastest_time = -1;
        while (!states.empty() && fastest_time == -1) {
            State top = states.front();
            states.pop();
            int x = top.x, y = top.y, time = top.time;
            for (int d = 0; d < 4; ++d) {
                int next_x = x + DIRECTIONS_X[d];
                int next_y = y + DIRECTIONS_Y[d];
                if (next_x >= 1 && next_y >= 1 && next_x <= R && next_y <= C) {
                    if (layout[next_x][next_y] != '#' && !visited[next_x][next_y]) {
                        if (time + 1 < fire_time[next_x][next_y]) {
                            visited[next_x][next_y] = true;
                            states.emplace(State(next_x, next_y, time + 1));
                        }
                    }
                } else {
                    fastest_time = time + 1;
                    break;
                }
            }
        }
        if (fastest_time == -1) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", fastest_time);
        }
    }

    return 0;
}
