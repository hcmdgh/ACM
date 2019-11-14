#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int heights[505][505];
bool visited[505][505];
int left[505][505];
int right[505][505];
const int DIRECTIONS_X[4] = {0, 0, 1, -1};
const int DIRECTIONS_Y[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int d = 0; d < 4; ++d) {
        int next_x = x + DIRECTIONS_X[d];
        int next_y = y + DIRECTIONS_Y[d];
        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && heights[next_x][next_y] < heights[x][y]) {
            if (!visited[next_x][next_y])
                dfs(next_x, next_y);
            left[x][y] = min(left[x][y], left[next_x][next_y]);
            right[x][y] = max(right[x][y], right[next_x][next_y]);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &heights[i][j]);
        }
    }

    memset(left, 0x3f, sizeof(left));
    memset(right, -1, sizeof(right));
    for (int j = 0; j < M; ++j) {
        left[N-1][j] = right[N-1][j] = j;
    }
    for (int j = 0; j < M; ++j) {
        if (!visited[0][j])
            dfs(0, j);
    }
    bool valid = true;
    int cnt = 0;
    for (int j = 0; j < M; ++j) {
        if (!visited[N-1][j]) {
            ++cnt;
            valid = false;
        }
    }
    if (!valid) {
        printf("0\n%d\n", cnt);
    } else {
        cnt = 0;
        int left_end = 0;
        while (left_end < M) {
            int right_end = 0;
            for (int j = 0; j < M; ++j) {
                if (left[0][j] <= left_end)
                    right_end = max(right_end, right[0][j]);
            }
            ++cnt;
            left_end = right_end + 1;
        }
        printf("1\n%d\n", cnt);
    }

    return 0;
}
