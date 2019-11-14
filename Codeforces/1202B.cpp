#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

typedef pair<int, int> Pair;
bool visited[10];
int ans[10][10];
int steps[10][10][10][10];  // 从i到j使用k和l的步数

int bfs(int src, int dest, int num1, int num2) {
    if (num1 == num2) {
        if (num1 == 0)
            return src == dest ? 1 : -1;
        memset(visited, 0, sizeof(visited));
        int cnt = 1;
        int temp = (src + num1) % 10;
        while (temp != dest && !visited[temp]) {
            visited[temp] = true;
            temp = (temp + num1) % 10;
            ++cnt;
        }
        return temp != dest ? -1 : cnt;
    }

    queue<Pair> states;
    states.emplace(Pair(src, 0));
    memset(visited, 0, sizeof(visited));
    visited[src] = true;
    while (!states.empty()) {
        Pair front = states.front();
        states.pop();
        int num = front.first;
        int step = front.second;
        int next1 = (num + num1) % 10;
        int next2 = (num + num2) % 10;
        if (next1 == dest || next2 == dest) {
            return step + 1;
        }
        if (!visited[next1]) {
            states.emplace(Pair(next1, step + 1));
            visited[next1] = true;
        }
        if (!visited[next2]) {
            states.emplace(Pair(next2, step + 1));
            visited[next2] = true;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                for (int m = 0; m <= 9; ++m) {
                    steps[i][j][k][m] = bfs(i, j, k, m);
                }
            }
        }
    }
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= i; ++j) {
            int cnt = 0;
            for (int k = 0; k < len - 1; ++k) {
                int step = steps[str[k]-'0'][str[k+1]-'0'][i][j];
                if (step > -1)
                    cnt += step - 1;
                else {
                    cnt = -1;
                    break;
                }
            }
            ans[i][j] = ans[j][i] = cnt;
        }
    }
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << ans[i][9] << endl;
    }

    return 0;
}
