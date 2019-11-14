#include <iostream>
#include <vector>
using namespace std;

int N;
int graph[55][55];
int deg[55];
vector<int> ans;

int char2idx(char ch) {
    if (ch <= 'Z')
        return ch - 'A' + 1;
    else
        return ch - 'a' + 27;
}

char idx2char(int idx) {
    if (idx <= 26)
        return 'A' + idx - 1;
    else
        return 'a' + idx - 27;
}

void dfs(int node) {
    for (int i = 1; i <= 52; ++i) {
        if (graph[node][i]) {
            --graph[node][i], --graph[i][node];
            dfs(i);
        }
    }
    ans.emplace_back(node);
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    char buffer[5];
    for (int i = 0; i < N; ++i) {
        scanf("%s", buffer);
        int src = char2idx(buffer[0]);
        int dest = char2idx(buffer[1]);
        ++graph[src][dest], ++graph[dest][src];
        ++deg[src], ++deg[dest];
    }
    int start = 99, _start = 99;
    bool solved = true;
    int odd_cnt = 0;
    for (int i = 1; i <= 52; ++i) {
        if (deg[i] & 1) {
            ++odd_cnt;
            if (odd_cnt > 2) {
                solved = false;
                break;
            }
            _start = min(_start, i);
        } else if (deg[i] > 0) {
            start = min(start, i);
        }
    }
    if (solved) {
        if (odd_cnt == 1) {
            solved = false;
        } else {
            if (odd_cnt == 2) {
                start = _start;
            }
            dfs(start);
            solved = ans.size() == N + 1;
        }
    }
    if (solved) {
        for (int i = ans.size() - 1; i >= 0; --i) {
            putchar(idx2char(ans[i]));
        }
        putchar('\n');
    } else {
        printf("No Solution\n");
    }

    return 0;
}
