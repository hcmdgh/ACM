#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const string VALID = "Ordering is possible.";
const string INVALID = "The door cannot be opened.";

int N;
int head[30];
struct Edge {
    int dest;
    int next;
} edges[100005];
int edges_cnt;
bool visited[30];
int in_degree[30], out_degree[30];

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

void dfs(int v) {
    if (!visited[v]) {
        visited[v] = true;
        int edge = head[v];
        while (edge > 0) {
            dfs(edges[edge].dest);
            edge = edges[edge].next;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> N;
        edges_cnt = 0;
        memset(head, 0, sizeof(head));
        memset(in_degree, 0, sizeof(in_degree));
        memset(out_degree, 0, sizeof(out_degree));
        for (int i = 0; i < N; ++i) {
            string word;
            cin >> word;
            char begin = word[0], end = word[word.size() - 1];
            int _begin = begin - 'a' + 1, _end = end - 'a' + 1;
            addEdge(_begin, _end);
            ++out_degree[_begin];
            ++in_degree[_end];
        }
        bool valid = true;
        bool temp1 = false, temp2 = false;
        int src = -1;
        for (int i = 1; i <= 26 && valid; ++i) {
            if (in_degree[i] != out_degree[i]) {
                if (in_degree[i] - out_degree[i] == 1) {
                    valid = !temp1;
                    temp1 = true;
                } else if (out_degree[i] - in_degree[i] == 1) {
                    src = i;
                    valid = !temp2;
                    temp2 = true;
                } else {
                    valid = false;
                }
            } else if (src == -1) {
                src = i;
            }
        }
        if (valid) {
            memset(visited, 0, sizeof(visited));
            dfs(src);
            for (int i = 1; i <= 26; ++i) {
                if (!visited[i] && head[i] > 0) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                cout << VALID << endl;
            else
                cout << INVALID << endl;
        } else {
            cout << INVALID << endl;
        }
    }

    return 0;
}
