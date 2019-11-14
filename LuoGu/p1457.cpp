#include <iostream>
#include <vector>
using namespace std;

const int UP = 2;
const int DOWN = 8;
const int LEFT = 1;
const int RIGHT = 4;
const int DIRECTIONS[4] = {UP, DOWN, LEFT, RIGHT};
const int DIRECTIONS_X[4] = {-1, 1, 0, 0};
const int DIRECTIONS_Y[4] = {0, 0, -1, 1};

int M, N;
int unit[50][50];
int room[50][50];
int room_area[2505];

struct Wall {
    int x, y, direction;
};

void dfs(int x, int y, int id) {
    if (x >= 0 && y >= 0 && x < N && y < M && room[x][y] == 0) {
        room[x][y] = id;
        int wall = unit[x][y];
        if ((wall & UP) == 0) {
            dfs(x-1, y, id);
        }
        if ((wall & DOWN) == 0) {
            dfs(x+1, y, id);
        }
        if ((wall & LEFT) == 0) {
            dfs(x, y-1, id);
        }
        if ((wall & RIGHT) == 0) {
            dfs(x, y+1, id);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> unit[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (room[i][j] == 0) {
                ++cnt;
                dfs(i, j, cnt);
            }
        }
    }

    cout << cnt << endl;

    int max_area = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ++room_area[room[i][j]];
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        max_area = max(max_area, room_area[i]);
    }

    cout << max_area << endl;

    Wall ans_wall;
    max_area = 0;
    for (int j = 0; j < M; ++j) {
        for (int i = N - 1; i >= 0; --i) {
            int wall = unit[i][j];
            for (int direction = 0; direction < 4; ++direction) {
                if (wall & DIRECTIONS[direction]) {
                    int x = i + DIRECTIONS_X[direction];
                    int y = j + DIRECTIONS_Y[direction];
                    if (x >= 0 && x < N && y >= 0 && y < M) {
                        int id1 = room[i][j];
                        int id2 = room[x][y];
                        if (id1 != id2) {
                            int area1 = room_area[id1];
                            int area2 = room_area[id2];
                            if (area1 + area2 > max_area) {
                                max_area = area1 + area2;
                                ans_wall.x = i;
                                ans_wall.y = j;
                                ans_wall.direction = DIRECTIONS[direction];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max_area << endl;
    cout << ans_wall.x+1 << ' ' << ans_wall.y+1 << ' ' << ((ans_wall.direction == UP) ? 'N' : 'E') << endl;

    return 0;
}
