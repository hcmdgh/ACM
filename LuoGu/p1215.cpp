#include <iostream>
#include <set>
using namespace std;

bool visited[21][21][21];
int A, B, C;
set<int> ans;

void dfs(int a, int b, int c) {
    if (!visited[a][b][c]) {
        visited[a][b][c] = true;
        // a -> b
        int move = min(a, B - b);
        if (move > 0)
            dfs(a - move, b + move, c);
        // a -> c
        move = min(a, C - c);
        if (move > 0)
            dfs(a - move, b, c + move);
        // b -> a
        move = min(b, A - a);
        if (move > 0)
            dfs(a + move, b - move, c);
        // b -> c
        move = min(b, C - c);
        if (move > 0)
            dfs(a, b - move, c + move);
        // c -> a
        move = min(c, A - a);
        if (move > 0)
            dfs(a + move, b, c - move);
        // c -> b
        move = min(c, B - b);
        if (move > 0)
            dfs(a, b + move, c - move);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> A >> B >> C;

    dfs(0, 0, C);
    for (int i = 0; i <= B; ++i) {
        for (int j = 0; j <= C; ++j) {
            if (visited[0][i][j]) {
                ans.emplace(j);
            }
        }
    }

    for (int val : ans) {
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}