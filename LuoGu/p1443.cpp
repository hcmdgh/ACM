#include <iostream>
#include <deque>
#include <iomanip>

using namespace std;

int N, M;
int src_x, src_y;
int steps[400][400];
const int DIRECTIONS_X[8] = {-2, -2, +2, +2, -1, -1, +1, +1};
const int DIRECTIONS_Y[8] = {-1, +1, -1, +1, -2, +2, -2, +2};

typedef pair<int, int> Point;

void dfs() {
    deque<Point> dq;
    steps[src_x][src_y] = 0;
    dq.emplace_back(Point(src_x, src_y));
    while (!dq.empty()) {
        Point point = dq.front();
        dq.pop_front();
        int current_x = point.first;
        int current_y = point.second;
        for (int i = 0; i < 8; ++i) {
            int new_x = current_x + DIRECTIONS_X[i];
            int new_y = current_y + DIRECTIONS_Y[i];
            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M) {
                if (steps[new_x][new_y] == -1) {
                    steps[new_x][new_y] = steps[current_x][current_y] + 1;
                    dq.emplace_back(Point(new_x, new_y));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin >> src_x >> src_y;
    --src_x, --src_y;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            steps[i][j] = -1;
        }
    }

    dfs();

    cout.setf(ios::left);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << setw(5) << steps[i][j];
        }
        cout << endl;
    }

    return 0;
}