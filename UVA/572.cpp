#include <iostream>
#include <cstring>
using namespace std;

int N, M;
bool layout[100][100];
int group[100][100];

void dfs(int x, int y, int idx) {
    if (x >= 0 && x < N && y >= 0 && y < M && layout[x][y] && group[x][y] == 0) {
        group[x][y] = idx;
        dfs(x + 1, y, idx);
        dfs(x - 1, y, idx);
        dfs(x + 1, y + 1, idx);
        dfs(x + 1, y - 1, idx);
        dfs(x, y + 1, idx);
        dfs(x, y - 1, idx);
        dfs(x - 1, y + 1, idx);
        dfs(x - 1, y - 1, idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    while ((cin >> N >> M) && N > 0 && M > 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                char ch;
                cin >> ch;
                layout[i][j] = ch == '@';
                group[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (layout[i][j] && group[i][j] == 0) {
                    ++cnt;
                    dfs(i, j, cnt);
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
