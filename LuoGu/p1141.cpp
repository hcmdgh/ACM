#include <iostream>
using namespace std;

const int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
};

int layout[1000][1000];
int ans[1000][1000];
bool visited[1000][1000];
int dq[100000000][2];

int main() {
    int N, M;
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char ch;
            cin >> ch;
            layout[i][j] = ch - '0';
        }
    }

    for (int i = 0; i < M; ++i) {
        int row, col;
        cin >> row >> col;
        --row, --col;
        if (ans[row][col] > 0) {
            cout << ans[row][col] << endl;
            continue;
        }
        dq[0][0] = row, dq[0][1] = col;
        visited[row][col] = true;
        int count = 1;
        int front_pos = 0;
        int dq_size = 1;
        while (front_pos < dq_size) {
            int point_x = dq[front_pos][0];
            int point_y = dq[front_pos][1];
            ++front_pos;
            for (int j = 0; j < 4; ++j) {
                int next_x = point_x + DIRECTIONS[j][0];
                int next_y = point_y + DIRECTIONS[j][1];
                if (next_x >= 0 && next_x < N &&
                    next_y >= 0 && next_y < N &&
                    !visited[next_x][next_y] &&
                    layout[point_x][point_y] != layout[next_x][next_y]) {
                    visited[next_x][next_y] = true;
                    ++count;
                    dq[dq_size][0] = next_x;
                    dq[dq_size][1] = next_y;
                    ++dq_size;
                }
            }
        }

        for (int j = 0; j < dq_size; ++j) {
            ans[dq[j][0]][dq[j][1]] = count;
        }
        cout << count << endl;
    }

    return 0;
}