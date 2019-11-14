#include <iostream>
#include <cstring>
using namespace std;

#define char2idx(ch) ((ch) - 'a')
const int REPEAT = 0;
const int WRONG = 1;
const int OK = 2;
const int UNVISITED = 1;
const int VISITED = 2;

// 字母表为全体小写字母的Trie
struct Trie {
    int table[500005][30];
    int val[500005];  // 每个字符串附加的值
    int nodes_cnt;

    Trie() {
        nodes_cnt = 1;
        memset(table[0], 0, sizeof(table[0]));
    }

    // 插入字符串s，附加信息v。注意v必须非0，因为0代表本结点不是单词结点。
    void insert(const char* s, int v = UNVISITED) {
        int node = 0;
        const char* ch = s;
        while (*ch) {
            int idx = char2idx(*ch);
            if (!table[node][idx]) {
                memset(table[nodes_cnt], 0, sizeof(table[nodes_cnt]));
                val[nodes_cnt] = 0;
                table[node][idx] = nodes_cnt++;
            }
            node = table[node][idx];
            ++ch;
        }
        val[node] = v;
    }

    // 查找字符串
    int search(const char* s) {
        int node = 0;
        const char* ch = s;
        while (*ch) {
            int idx = char2idx(*ch);
            if (!table[node][idx]) {
                return WRONG;
            }
            node = table[node][idx];
            ++ch;
        }
        if (!val[node]) {
            return WRONG;
        } else if (val[node] == VISITED) {
            return REPEAT;
        } else {
            val[node] = VISITED;
            return OK;
        }
    }
} tree;

int N, M;
char buffer[55];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", buffer);
        tree.insert(buffer);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%s", buffer);
        int res = tree.search(buffer);
        if (res == OK) {
            printf("OK\n");
        } else if (res == WRONG) {
            printf("WRONG\n");
        } else {
            printf("REPEAT\n");
        }
    }

    return 0;
}
