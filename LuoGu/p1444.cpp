#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
typedef pair<int, int> Hole;
Hole holes[12];
int to[12];  // 存储通过行走连接的图
int _to[12];  // 存储通过虫洞连接的图
bool visited[12];
int ans = 0;

bool cmp(const Hole& hole1, const Hole& hole2) {
    return hole1.second < hole2.second ||
        (hole1.second == hole2.second && hole1.first < hole2.first);
}

// 判断以某个结点为起点是否有回路
bool cycle(int v) {
    while (v != -1) {
        if (visited[v])
            return true;
        visited[v] = true;
        v = to[_to[v]];
    }
    return false;
}

void dfs(int i) {
    if (i >= N) {
        bool valid = false;
        for (int j = 0; j < N; ++j) {
            memset(visited, 0, N);
            if (cycle(j)) {
                valid = true;
                break;
            }
        }
        if (valid) {
            ++ans;
        }
    } else if (_to[i] == -1) {
        for (int j = i + 1; j < N; ++j) {
            if (_to[j] == -1) {
                _to[i] = j, _to[j] = i;
                dfs(i + 1);
                _to[i] = -1, _to[j] = -1;
            }
        }
    } else {
        dfs(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> holes[i].first >> holes[i].second;
    }

    sort(holes, holes + N, cmp);
    memset(to, -1, sizeof(int) * N);
    for (int i = 0; i < N - 1; ++i) {
        if (holes[i].second == holes[i+1].second) {
            to[i] = i + 1;
        }
    }

    memset(_to, -1, sizeof(int) * N);
    dfs(0);
    cout << ans << endl;

    return 0;
}