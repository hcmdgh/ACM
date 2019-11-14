#include <iostream>
#include <cstring>
#include <map>
using namespace std;

struct Node {
    char str[5];
    int hash;
    int left_child, right_child;
    int len;

    void clear() {
        hash = left_child = right_child = len = 0;
        memset(str, 0, sizeof(str));
    }

    void append(char ch) {
        str[len++] = ch;
        hash = hash * 27 + ch - 'a' + 1;
    }

    bool operator<(const Node& other) const {
        if (hash != other.hash)
            return hash < other.hash;
        if (left_child != other.left_child)
            return left_child < other.left_child;
        return right_child < other.right_child;
    }
} nodes[50005];

const char* ptr;
int T, nodes_cnt;
char buffer[300005];
map<Node, int> node2idx;
int visited[50005];

int parse() {
    ++nodes_cnt;
    int _nodes_cnt = nodes_cnt;
    Node& node = nodes[nodes_cnt];
    node.clear();
    while (*ptr >= 'a' && *ptr <= 'z') {
        node.append(*ptr);
        ++ptr;
    }
    if (*ptr == '(') {
        ++ptr;
        node.left_child = parse();
        ++ptr;
        node.right_child = parse();
        ++ptr;
    }
    if (node2idx.count(node)) {
        --nodes_cnt;
        return node2idx[node];
    } else {
//        nodes[_nodes_cnt] = node;
        return node2idx[node] = _nodes_cnt;
    }
}

void print_tree(int root) {
    Node& node = nodes[root];
    if (visited[root] != T + 5) {
        printf("%s", node.str);
        visited[root] = T + 5;
        if (node.left_child) {
            putchar('(');
            print_tree(node.left_child);
            putchar(',');
            print_tree(node.right_child);
            putchar(')');
        }
    } else {
        printf("%d", root);
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%s", buffer);
        ptr = buffer;
        nodes_cnt = 0;
        node2idx.clear();
//        memset(visited, 0, sizeof(visited));
        int root = parse();
        print_tree(root);
        putchar('\n');
    }

    return 0;
}
