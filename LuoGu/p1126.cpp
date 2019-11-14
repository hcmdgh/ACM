#include <iostream>
#include <deque>
using namespace std;

const int EAST = 0;
const int SOUTH = 1;
const int WEST = 2;
const int NORTH = 3;

const int DIRECTIONS_X[4] = {0, 1, 0, -1};
const int DIRECTIONS_Y[4] = {1, 0, -1, 0};

struct Status {
    int x, y;
    int orientation;
    int time;

    Status(int x, int y, int orientation, int time) :
            x(x), y(y), orientation(orientation), time(time) {}
};

int layout[50][50];
int visited[50][50];
int N, M;
int src_x, src_y, dest_x, dest_y;
deque<Status> dq;

inline bool isInRange(int x, int y) {
    return x - 1 >= 0 &&
        y - 1 >= 0 &&
        x < N &&
        y < M;
}

inline bool isBlocked(int x, int y) {
    return layout[x-1][y-1] ||
        layout[x-1][y] ||
        layout[x][y-1] ||
        layout[x][y];
}

inline bool isVisited(int x, int y, int orientation) {
    int val = visited[x][y];
    return (val & (1 << orientation)) != 0;
}

inline void setVisited(int x, int y, int orientation) {
    visited[x][y] |= (1 << orientation);
}

void dfs() {
    while (!dq.empty()) {
        Status status = dq.front();
        dq.pop_front();
        int status_x = status.x;
        int status_y = status.y;
        int status_orientation = status.orientation;
        int status_time = status.time;

        if (status_x == dest_x && status_y == dest_y) {
            cout << status_time << endl;
            return;
        }

        int new_orientation = (status_orientation + 5) % 4;
        if (!isVisited(status_x, status_y, new_orientation)) {
            dq.emplace_back(Status(status_x, status_y, new_orientation, status_time + 1));
            setVisited(status_x, status_y, new_orientation);
        }
        new_orientation = (status_orientation + 3) % 4;
        if (!isVisited(status_x, status_y, new_orientation)) {
            dq.emplace_back(Status(status_x, status_y, new_orientation, status_time + 1));
            setVisited(status_x, status_y, new_orientation);
        }

        int delta_x = DIRECTIONS_X[status_orientation];
        int delta_y = DIRECTIONS_Y[status_orientation];
        for (int step = 0; step < 3; ++step) {
            status_x += delta_x;
            status_y += delta_y;
            if (isInRange(status_x, status_y) &&
                !isBlocked(status_x, status_y)) {
                if (!isVisited(status_x, status_y, status_orientation)) {
                    dq.emplace_back(Status(status_x, status_y, status_orientation, status_time + 1));
                    setVisited(status_x, status_y, status_orientation);
                }
            } else
                break;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> layout[i][j];
        }
    }
    // src_x和src_y为机器人右下角的坐标
    int orientation;
    char temp;
    cin >> src_x >> src_y >> dest_x >> dest_y >> temp;
    if (src_x == dest_x && src_y == dest_y) {
        cout << 0 << endl;
        return 0;
    }
    switch (temp) {
        case 'E':
            orientation = EAST;
            break;
        case 'W':
            orientation = WEST;
            break;
        case 'N':
            orientation = NORTH;
            break;
        default:
            orientation = SOUTH;
    }

    dq.emplace_back(Status(src_x, src_y, orientation, 0));
    setVisited(src_x, src_y, orientation);

    dfs();

    return 0;
}