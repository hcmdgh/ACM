#include <cstdio>
#include <vector>
using namespace std;

int N, M;

vector<vector<bool>> layout;
vector<vector<bool>> visited;
vector<vector<bool>> mark;

char readChar() {
    char ch;
    do {
        ch = getchar();
    } while (ch != '.' && ch != '#');
    return ch;
}

bool dfs(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M && layout[x][y] && !visited[x][y] && !mark[x][y]) {
        visited[x][y] = true;
        if (x == N - 1 && y == M - 1) {
            return true;
        }
        if (dfs(x + 1, y) || dfs(x, y + 1)) {
            mark[x][y] = true;
            return true;
        } else
            return false;
    } else {
        return false;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    layout.resize(N, vector<bool>(M));
    visited.resize(N, vector<bool>(M, false));
    mark.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char ch = readChar();
            layout[i][j] = ch == '.';
        }
    }
    if (dfs(0, 0)) {
        mark[0][0] = false;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                visited[i][j] = false;
        if (dfs(0, 0)) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    } else {
        printf("0\n");
    }

    return 0;
}
