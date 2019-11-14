#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

const int BLACK = 0;
const int WHITE = 1;
const int MIXED = 2;
bool layout[32][32];

struct Node {
    int val;
    Node *child1, *child2, *child3, *child4;

    Node(int val) : val(val), child1(nullptr), child2(nullptr), child3(nullptr), child4(nullptr) {}
};

Node* buildTree() {
    char ch;
    cin >> ch;
    Node* root;
    if (ch == 'f') {
        root = new Node(BLACK);
    } else if (ch == 'e') {
        root = new Node(WHITE);
    } else if (ch == 'p') {
        root = new Node(MIXED);
        root->child1 = buildTree();
        root->child2 = buildTree();
        root->child3 = buildTree();
        root->child4 = buildTree();
    } else {
        assert(0);
    }
    return root;
}

void paint(Node* root, int x1, int y1, int x2, int y2) {
    int gap = (x2 - x1 + 1) >> 1;
    if (root) {
        if (root->val == BLACK) {
//            cout << "x1y1x2y2" << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            for (int i = x1; i <= x2; ++i) {
                for (int j = y1; j <= y2; ++j) {
                    layout[i][j] = true;
                }
            }
        } else if (root->val == MIXED) {
            paint(root->child1, x1, y1 + gap, x1 + gap - 1, y2);
            paint(root->child2, x1, y1, x1 + gap - 1, y1 + gap - 1);
            paint(root->child3, x1 + gap, y1, x2, y1 + gap - 1);
            paint(root->child4, x1 + gap, y1 + gap, x2, y2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q--) {
        Node* tree1 = buildTree();
        Node* tree2 = buildTree();
        memset(layout, 0, sizeof(layout));
        paint(tree1, 0, 0, 31, 31);
        paint(tree2, 0, 0, 31, 31);
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < 32; ++j) {
                cnt += layout[i][j];
            }
        }
        cout << "There are " << cnt << " black pixels." << endl;
    }

    return 0;
}
